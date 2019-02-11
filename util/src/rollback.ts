#!/usr/local/bin/node

/**
 * util/rollback.js
 * Rollback latest project
 * Copyright (c) 2019 Seungho Kim.
 */

import chalk from "chalk";
import crypto from "crypto";
import figlet from "figlet";
import fs from "fs";
import ora from "ora";
import path from "path";
import program from "commander";
import readline from "readline";
import util from "util";

const SCRIPT_VERSION = "0.1.0";

program
  .version(SCRIPT_VERSION, "-v, --version")
  .option("-y, --yes", "automatic yes to prompts")
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
  console.log(chalk.blue(figlet.textSync("Util/Rollback")));
  console.log();
}

async function main() {
  await init();

  const operationGranted =
    program.yes || (await ask("롤백을 시작할까요? [y/N]: ")) == "y";

  if (!operationGranted) {
    ora("작업을 종료합니다.").fail();
    process.exit(1);
  }

  console.log();
  console.log(chalk.yellow("작업을 시작합니다."));
  console.log();

  const projectPath = path.join(__dirname, "..");

  let latestDirNum = 1;
  while (fs.existsSync(path.join(projectPath, `${latestDirNum}`))) {
    ++latestDirNum;
  }
  --latestDirNum;

  const step1 = ora(`프로젝트 테스트 디렉토리 제거`).start();
  fs.readdirSync(path.join(projectPath, `${latestDirNum}/test`)).forEach(file =>
    fs.unlinkSync(path.join(projectPath, `${latestDirNum}/test/${file}`))
  );
  fs.rmdirSync(path.join(projectPath, `${latestDirNum}/test`));
  step1.succeed();

  const step2 = ora(`프로젝트 디렉토리 제거`).start();
  fs.readdirSync(path.join(projectPath, `${latestDirNum}`)).forEach(file =>
    fs.unlinkSync(path.join(projectPath, `${latestDirNum}/${file}`))
  );
  fs.rmdirSync(path.join(projectPath, `${latestDirNum}`));
  step2.succeed();

  const step3 = ora(`README.md 수정`).start();
  let readme = fs.readFileSync(path.join(projectPath, "README.md")).toString();
  readme = readme
    .split("\n")
    .filter(
      line =>
        !line.includes(
          `https://github.com/niceb5y/algorithm-study/blob/niceb5y/${latestDirNum}`
        )
    )
    .join("\n");
  fs.writeFileSync(path.join(projectPath, "README.md"), readme);
  step3.succeed();

  const step4 = ora(`.travis.yml 수정`).start();
  let travisConf = fs
    .readFileSync(path.join(projectPath, ".travis.yml"))
    .toString();
  travisConf = travisConf.replace(
    `"cd ${latestDirNum}"`,
    `"cd ${latestDirNum - 1}"`
  );
  fs.writeFileSync(path.join(projectPath, ".travis.yml"), travisConf);
  step4.succeed();

  console.log();
  console.log(chalk.green(`✨ 작업 완료 ✨`));
  console.log();
}

main();
