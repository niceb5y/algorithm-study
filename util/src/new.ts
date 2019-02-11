#!/usr/local/bin/node

/**
 * util/new.js
 * Boilerplate generator
 * Copyright (c) 2019 Seungho Kim.
 */

import axios from "axios";
import chalk from "chalk";
import cheerio from "cheerio";
import figlet from "figlet";
import fs from "fs";
import ora from "ora";
import path from "path";
import program from "commander";
import readline from "readline";
import util from "util";

const SCRIPT_VERSION = "0.1.1";

program
  .version(SCRIPT_VERSION, "-v, --version")
  .option(
    "-l --lang <lang>",
    'programming language ["cpp", "go"]',
    /^(cpp|go)$/i,
    "cpp"
  )
  .parse(process.argv);

async function ask(query: string): Promise<string> {
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  });
  const result = await util.promisify<string, string>(
    (question: string, callback: Function) => {
      rl.question(question, callback.bind(null, null));
    }
  )(query);
  rl.close();
  return result;
}

async function init() {
  console.clear();
  console.log(chalk.blue(figlet.textSync("Util/New")));
  console.log();
}

async function main() {
  await init();

  const problemNum = parseInt(
    (program.args.length == 1
      ? program.args[0]
      : await ask("어떤 문제를 푸시겠습니까?: ")
    ).replace("https://www.acmicpc.net/problem/", "")
  );

  if (problemNum < 1000 || isNaN(problemNum) || !isFinite(problemNum)) {
    ora("올바르지 않은 입력입니다.").fail();
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

  const step1 = ora(`프로젝트 디렉토리 생성`).start();
  fs.mkdirSync(path.join(projectPath, `${newDirNum}`));
  step1.succeed();

  const step2 = ora(`프로젝트 테스트 디렉토리 생성`).start();
  fs.mkdirSync(path.join(projectPath, `${newDirNum}/test`));
  step2.succeed();

  const step3 = ora(`Makefile 파일 생성`).start();
  fs.copyFileSync(
    path.join(__dirname, `/templates/Makefile_${program.lang}`),
    path.join(projectPath, `${newDirNum}`, "Makefile")
  );
  step3.succeed();

  const step4 = ora(`main.${program.lang} 파일 생성`).start();
  fs.copyFileSync(
    path.join(__dirname, `/templates/boilerplate_${program.lang}`),
    path.join(projectPath, `${newDirNum}`, `main.${program.lang}`)
  );
  step4.succeed();

  const step5 = ora(`문제 정보 다운로드`).start();
  const res = await axios.get(`https://www.acmicpc.net/problem/${problemNum}`);
  const body = res.data;
  const $ = cheerio.load(body);
  const htmlTitle = $("title").text();
  step5.succeed(`${htmlTitle} 문제 정보 다운로드`);

  const step6 = ora(`테스트 케이스 입력 생성`).start();
  let sampleInput = 1,
    sampleOutput = 1;
  while ($(`#sample-input-${sampleInput}`).length > 0) {
    let text = $(`#sample-input-${sampleInput}`).text();
    if (text === "") {
      ++sampleInput;
      continue;
    }
    if (!text.endsWith("\n")) text += "\n";
    fs.writeFileSync(
      path.join(projectPath, `${newDirNum}`, `test/${sampleInput}.input`),
      text
    );
    ++sampleInput;
  }
  step6.succeed();

  const step7 = ora(`테스트 케이스 출력 생성`).start();
  while ($(`#sample-output-${sampleOutput}`).length > 0) {
    let text = $(`#sample-output-${sampleOutput}`).text();
    if (!text.endsWith("\n")) text += "\n";
    fs.writeFileSync(
      path.join(projectPath, `${newDirNum}`, `test/${sampleOutput}.answer`),
      text
    );
    ++sampleOutput;
  }
  step7.succeed();

  const step8 = ora(`README.md 수정`).start();
  const timezoneOffset = new Date().getTimezoneOffset() * 60000;
  const today = new Date(Date.now() - timezoneOffset)
    .toISOString()
    .substring(0, 10);
  let readme = fs.readFileSync(path.join(projectPath, "README.md")).toString();
  const problemTitle = htmlTitle.split(": ")[1];
  readme = readme.replace(
    "\n\n## 참고 링크",
    `\n- ${today} ${problemTitle} [\\[문제\\]](https://www.acmicpc.net/problem/${problemNum}) [\\[코드\\]](https://github.com/niceb5y/algorithm-study/blob/niceb5y/${newDirNum}/main.${
      program.lang
    })\n\n## 참고 링크`
  );
  fs.writeFileSync(path.join(projectPath, "README.md"), readme);
  step8.succeed();

  const step9 = ora(`.travis.yml 수정`).start();
  let travisConf = fs
    .readFileSync(path.join(projectPath, ".travis.yml"))
    .toString();
  travisConf = travisConf.replace(`"cd ${newDirNum - 1}"`, `"cd ${newDirNum}"`);
  fs.writeFileSync(path.join(projectPath, ".travis.yml"), travisConf);
  step9.succeed();

  console.log();
  console.log(chalk.green(`✨ 작업 완료 ✨`));
  console.log();
  console.log(
    chalk.blue(`'cd ${newDirNum}'(으)로 ${problemTitle}의 풀이를 시작하세요.`)
  );
  console.log();
}

main();
