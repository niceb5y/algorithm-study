"use strict";
/**
 * util/new.js
 * Boilerplate generator
 * Copyright (c) 2019 Seungho Kim.
 */
var readline = require("readline");
var fs = require("fs");
var path = require("path");
var cheerio = require("cheerio");
var axios = require("axios");
var figlet = require("figlet");
var chalk = require("chalk");
var ora = require("ora");
var rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});
console.clear();
console.log(chalk.blue(figlet.textSync("Util/New")));
console.log();
rl.question("어떤 문제를 푸시겠습니까?: ", function (problem) {
    var problemNum = problem.replace("https://www.acmicpc.net/problem/", "");
    rl.close();
    if (problemNum < 1000 ||
        isNaN(parseInt(problemNum)) ||
        !isFinite(problemNum)) {
        console.error("올바르지 않은 입력입니다.");
        process.exit(1);
    }
    console.log();
    console.log(chalk.yellow("작업을 시작합니다."));
    console.log();
    var projectPath = path.join(__dirname, "..");
    var newDirNum = 1;
    while (fs.existsSync(path.join(projectPath, "" + newDirNum))) {
        ++newDirNum;
    }
    var step1 = ora("\uB514\uB809\uD1A0\uB9AC " + newDirNum + " \uC0DD\uC131").start();
    fs.mkdirSync(path.join(projectPath, "" + newDirNum));
    step1.succeed();
    var step2 = ora("\uB514\uB809\uD1A0\uB9AC " + newDirNum + "/test \uC0DD\uC131").start();
    fs.mkdirSync(path.join(projectPath, newDirNum + "/test"));
    step2.succeed();
    var step3 = ora("\uD30C\uC77C " + newDirNum + "/Makefile \uC0DD\uC131").start();
    fs.copyFileSync(path.join(__dirname, "/templates/Makefile"), path.join(projectPath, "" + newDirNum, "Makefile"));
    step3.succeed();
    var step4 = ora("\uD30C\uC77C " + newDirNum + "/main.cpp \uC0DD\uC131").start();
    fs.copyFileSync(path.join(__dirname, "/templates/main.cpp"), path.join(projectPath, "" + newDirNum, "main.cpp"));
    step4.succeed();
    axios
        .get("https://www.acmicpc.net/problem/" + problemNum)
        .then(function (res) {
        var body = res.data;
        var $ = cheerio.load(body);
        var htmlTitle = $("title").text();
        var step5 = ora(htmlTitle + " \uBB38\uC81C \uC815\uBCF4 \uB2E4\uC6B4\uB85C\uB4DC").start();
        step5.succeed();
        var problemTitle = htmlTitle.split(": ")[1];
        var sampleInput = 1, sampleOutput = 1;
        while ($("#sample-input-" + sampleInput).length > 0) {
            var text = $("#sample-input-" + sampleInput).text();
            if (text === "") {
                ++sampleInput;
                continue;
            }
            if (!text.endsWith("\n"))
                text += "\n";
            fs.writeFileSync(path.join(projectPath, "" + newDirNum, "test/" + sampleInput + ".input"), text);
            var step6 = ora("\uD30C\uC77C " + newDirNum + "/test/" + sampleInput + " \uC0DD\uC131").start();
            step6.succeed();
            ++sampleInput;
        }
        while ($("#sample-output-" + sampleOutput).length > 0) {
            var text = $("#sample-output-" + sampleOutput).text();
            if (!text.endsWith("\n"))
                text += "\n";
            fs.writeFileSync(path.join(projectPath, "" + newDirNum, "test/" + sampleOutput + ".answer"), text);
            var step7 = ora("\uD30C\uC77C " + newDirNum + "/test/" + sampleOutput + " \uC0DD\uC131").start();
            step7.succeed();
            ++sampleOutput;
        }
        var step8 = ora("README.md \uC218\uC815").start();
        var timezoneOffset = new Date().getTimezoneOffset() * 60000;
        var today = new Date(Date.now() - timezoneOffset)
            .toISOString()
            .substring(0, 10);
        var readme = fs
            .readFileSync(path.join(projectPath, "README.md"))
            .toString();
        readme = readme.replace("\n\n## 참고 링크", "\n- " + today + " " + problemTitle + " [\\[\uBB38\uC81C\\]](https://www.acmicpc.net/problem/" + problemNum + ") [\\[\uCF54\uB4DC\\]](https://github.com/niceb5y/algorithm-study/blob/niceb5y/" + newDirNum + "/main.cpp)\n\n## \uCC38\uACE0 \uB9C1\uD06C");
        fs.writeFileSync(path.join(projectPath, "README.md"), readme);
        step8.succeed();
        var step9 = ora(".travis.yml \uC218\uC815").start();
        var travisConf = fs
            .readFileSync(path.join(projectPath, ".travis.yml"))
            .toString();
        travisConf = travisConf.replace("\"cd " + (newDirNum - 1) + "\"", "\"cd " + newDirNum + "\"");
        fs.writeFileSync(path.join(projectPath, ".travis.yml"), travisConf);
        step9.succeed();
        console.log();
        console.log(chalk.green("\u2728 \uC791\uC5C5 \uC644\uB8CC \u2728"));
        console.log();
        console.log(chalk.blue("'cd " + newDirNum + "'(\uC73C)\uB85C " + problemTitle + "\uC758 \uD480\uC774\uB97C \uC2DC\uC791\uD558\uC138\uC694."));
        console.log();
    });
});
