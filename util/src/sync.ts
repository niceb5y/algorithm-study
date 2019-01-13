/**
 * util/sync.js
 * Sync project configs
 * Copyright (c) 2019 Seungho Kim.
 */

import chalk from "chalk";
import crypto from "crypto";
import figlet from "figlet";
import fs from "fs";
import ora from "ora";
import path from "path";

function getHash(path: string): string {
  const file = fs.readFileSync(path);
  const sha1 = crypto.createHash("sha1");
  sha1.update(file);
  return sha1.digest("hex");
}

function init() {
  console.clear();
  console.log(chalk.blue(figlet.textSync("Util/Migrate")));
  console.log();
}

function main() {
  init();

  console.log();
  console.log(chalk.yellow("작업을 시작합니다."));
  console.log();

  const projectPath = path.join(__dirname, "..");
  const makefilePath = path.join(__dirname, "templates/Makefile");
  const makefileHash = getHash(makefilePath);

  const step1 = ora("Makefile 동기화").start();
  let newDirNum = 1;
  while (fs.existsSync(path.join(projectPath, `${newDirNum}`))) {
    const projectMakefilePath = path.join(projectPath, `${newDirNum}/Makefile`);
    const projectMakefileHash = getHash(projectMakefilePath);
    const projectMakefileExists = fs.existsSync(projectMakefilePath);
    if (!projectMakefileExists || makefileHash != projectMakefileHash) {
      fs.copyFileSync(makefilePath, projectMakefilePath);
      step1.info(`${newDirNum}/Makefile 업데이트`);
    }
    ++newDirNum;
  }
  step1.succeed();

  console.log();
  console.log(chalk.green(`✨ 작업 완료 ✨`));
  console.log();
  console.log(chalk.blue(`모든 프로젝트 설정이 최신입니다.`));
  console.log();
}

main();
