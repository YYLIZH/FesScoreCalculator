const getData = () => {
    let gameTypes = document.getElementsByName("gameType")
    let gameType;
    for (let i = 0; i < gameTypes.length; i++) {
        if (gameTypes[i].checked) {
            gameType = gameTypes[i].value;
        }
    }
    let handlights = document.getElementsByName("handlight")
    let handlight;
    handlights.forEach(el => {
        if (el.checked) {
            handlight = el.value;
        }
    })
    let bonus = document.getElementById("bonus").value;

    let scoreDiff = document.getElementById("targetScore").value - document.getElementById("presentScore").value;

    return {
        gameType: gameType,
        handlight: handlight,
        bonus: bonus,
        scoreToCalculate: scoreDiff
    }
}

const readCoinFile = async (file) => {
    const response = await fetch(file)
    const text = await response.text()
    let goals = []
    let combos = []
    let levels = []
    let scores = []
    let els;
    let lines = text.split("\n")
    for (let i = 0; i < lines.length; i++) {
        if (lines[i]) {
            els = lines[i].split("\t")
            goals.push(els[0].split(' ')[0])
            combos.push(els[0].split(' ')[1])
            levels.push(els[1])
            scores.push(Number(els[2].split('\r')[0]))
        }
    }
    return {
        goals: goals,
        combos: combos,
        levels: levels,
        scores: scores
    }
}

const readProsFile = async (file) => {
    const response = await fetch(file)
    const text = await response.text()
    let ratios = []
    let goals = []
    let combos = []
    let levels = []
    let scores = []
    let els;
    let lines = text.split("\n")
    for (let i = 0; i < lines.length; i++) {
        if (lines[i]) {
            els = lines[i].split("\t")
            ratios.push(els[0])
            goals.push(els[1].split(' ')[0])
            combos.push(els[1].split(' ')[1])
            levels.push(els[2])
            scores.push(Number(els[3].split('\r')[0]))
        }
    }
    return {
        ratios: ratios,
        goals: goals,
        combos: combos,
        levels: levels,
        scores: scores
    }
}

const leastScores = async (scores, target_score) => {
    let dp = Array(target_score + 1).fill(target_score + 1)
    let p = Array(target_score + 1).fill(0)
    dp[0] = 0;
    let done = 0;

    let task = new Promise((resolve) => {
        for (let i = 1; i <= target_score; i++) {
            for (let j = 0; j < scores.length; j++) {
                if (scores[j] <= i) {
                    if (dp[i] > dp[i - scores[j]] + 1) {
                        dp[i] = dp[i - scores[j]] + 1;
                        p[i] = scores[j]
                        resolve()
                    }
                }
            }

        }

    })
    await Promise.all([task])
    if (dp[target_score] > target_score) {
        console.log("hihi")
        let wrong = []
        return [-1, wrong]
    } else {
        return [dp[target_score], p]
    }

}

const parse_result = async (scoreToCalculate, array) => {
    console.log(array)
    let result_dict = {}
    let index
    while (scoreToCalculate > 0) {
        index = array.indexOf(scoreToCalculate)
        result_dict[index] == undefined ? 1 : result_dict[index] += 1
        scoreToCalculate -= array[scoreToCalculate]
    }
    return result_dict
}


document.getElementById("calculateBtn").onclick = async () => {
    let {
        gameType,
        handlight,
        bonus,
        scoreToCalculate
    } = getData()
    if (gameType == "coin") {
        let input_data = (handlight == "True") ? `./static/coin_50_${bonus}.txt` : `./static/coin_${bonus}.txt`
        let {
            goal,
            combos,
            levels,
            scores
        } = await readCoinFile(input_data)
        let calculate_result = await leastScores(scores, scoreToCalculate)
        console.log(calculate_result)
        let result = await parse_result(scoreToCalculate, calculate_result[1])
        console.log(calculate_result)

    } else if (gameType == "pros") {
        let input_data = (handlight == "True") ? `./static/pros_50_${bonus}.txt` : `./static/pros_${bonus}.txt`
        let ratios, goal, combos, levels, scores = readProsFile(input_data)
    }
}