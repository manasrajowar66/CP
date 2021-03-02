process.stdin.resume();
process.stdin.setEncoding("utf-8");

let standardInputString = "";
let currentLine = 0;

const readline = () => standardInputString[currentLine++];

process.stdin.on("data", (rawdata) => {
  standardInputString += rawdata;
});

process.stdin.on("end", (_) => {
  standardInputString = standardInputString
    .trim()
    .split("\n")
    .map((line) => line.trim());
  main();
});
const memo = new Array(3009).fill(-1.0).map(() => new Array(3009).fill(-1.0));
const coins = (arr, heads, ind) => {
  if (memo[heads][ind] != -1.0) return memo[heads][ind];
  if (ind === arr.length) {
    if (heads > arr.length - heads) return 1.0;
    else return 0.0;
  }
  let res1 = 0.0,
    res2 = 0.0;
  res1 += arr[ind] * coins(arr, heads + 1, ind + 1);
  res2 += (1.0 - arr[ind]) * coins(arr, heads, ind + 1);
  return (memo[heads][ind] = res1 + res2);
};

const main = () => {
  let n = parseInt(readline());
  const arr = readline()
    .split(" ")
    .map((key) => parseFloat(key));
  console.log(coins(arr, 0, 0));
};
