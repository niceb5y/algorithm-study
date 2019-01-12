/**
 * util/new.js
 * Boilerplate generator
 * Copyright (c) 2019 Seungho Kim.
 */

const readline = require("readline");
const fs = require("fs");
const path = require("path");
const cheerio = require("cheerio");
const axios = require("axios");
const figlet = require("figlet");
const chalk = require("chalk");
const ora = require("ora");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

console.clear();
console.log(chalk.blue(figlet.textSync("Util/New")));
console.log();
rl.question("어떤 문제를 푸시겠습니까?: ", (problem: any) => {
  const problemNum = problem.replace("https://www.acmicpc.net/problem/", "");
  rl.close();
  if (
    problemNum < 1000 ||
    isNaN(parseInt(problemNum)) ||
    !isFinite(problemNum)
  ) {
    console.error("올바르지 않은 입력입니다.");
    process.exit(1);
  }
  console.log();
  console.log(chalk.yellow("작업을 시작합니다."));
  console.log();

  const projectPath = path.join(__dirname, "..");
  let newDirNum = 1;
  while (fs.existsSync(path.join(projectPath, `${newDirNum}`))) {
    ++newDirNum;
  }
  const step1 = ora(`디렉토리 ${newDirNum} 생성`).start();
  fs.mkdirSync(path.join(projectPath, `${newDirNum}`));
  step1.succeed();
  const step2 = ora(`디렉토리 ${newDirNum}/test 생성`).start();
  fs.mkdirSync(path.join(projectPath, `${newDirNum}/test`));
  step2.succeed();
  const step3 = ora(`파일 ${newDirNum}/Makefile 생성`).start();
  fs.copyFileSync(
    path.join(__dirname, "/templates/Makefile"),
    path.join(projectPath, `${newDirNum}`, "Makefile")
  );
  step3.succeed();
  const step4 = ora(`파일 ${newDirNum}/main.cpp 생성`).start();
  fs.closeSync(
    fs.openSync(path.join(projectPath, `${newDirNum}`, "main.cpp"), "w")
  );
  step4.succeed();
  axios
    .get(`https://www.acmicpc.net/problem/${problemNum}`)
    .then((res: any) => {
      const body = res.data;
      const $ = cheerio.load(body);
      const htmlTitle = $("title").text();
      const step5 = ora(`${htmlTitle} 문제 정보 다운로드`).start();
      step5.succeed();
      const problemTitle = htmlTitle.split(": ")[1];
      let sampleInput = 1,
        sampleOutput = 1;
      while ($(`#sample-input-${sampleInput}`).length > 0) {
        let text = $(`#sample-input-${sampleInput}`).text();
        fs.writeFileSync(
          path.join(projectPath, `${newDirNum}`, `test/${sampleInput}.input`),
          text
        );
        const step6 = ora(`파일 ${newDirNum}/test/${sampleInput} 생성`).start();
        step6.succeed();
        ++sampleInput;
      }
      while ($(`#sample-output-${sampleOutput}`).length > 0) {
        let text = $(`#sample-output-${sampleOutput}`).text();
        fs.writeFileSync(
          path.join(projectPath, `${newDirNum}`, `test/${sampleOutput}.answer`),
          text
        );
        const step7 = ora(
          `파일 ${newDirNum}/test/${sampleOutput} 생성`
        ).start();
        step7.succeed();
        ++sampleOutput;
      }
      const timezoneOffset = new Date().getTimezoneOffset() * 60000;
      const today = new Date(Date.now() - timezoneOffset)
        .toISOString()
        .substring(0, 10);
      let readme = fs
        .readFileSync(path.join(projectPath, "README.md"))
        .toString();
      readme = readme.replace(
        "\n\n## 참고 링크",
        `\n- ${today} ${problemTitle} [\\[문제\\]](https://www.acmicpc.net/problem/${problemNum}) [\\[코드\\]](https://github.com/niceb5y/algorithm-study/blob/niceb5y/${newDirNum}/main.cpp)\n\n## 참고 링크`
      );
      fs.writeFileSync(path.join(projectPath, "README.md"), readme);
      const step8 = ora(`README.md 수정`).start();
      step8.succeed();
      console.log();
      console.log(chalk.green(`✨ 작업 완료 ✨`));
      console.log();
    });
});
