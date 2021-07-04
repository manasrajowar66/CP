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

const main = () => {
  let t = parseInt(readline());

  while (t--) {
    let n = parseInt(readline());
    const arr = readline()
      .split(" ")
      .map((key, index) => ({
        index: index + 1,
        key: parseInt(key),
      }));

    if (n == 2) {
      console.log(1);
      continue;
    }

    const arr2 = [];
    arr2.push(arr[0]);
    arr2.push(arr[1]);
    let ans = 1,
      len = arr2.length;

    for (let i = 2; i < n; i++) {
      while (arr2.length >= 2) {
        let val1 =
          (arr2[len - 1].key - arr2[len - 2].key) /
          (arr2[len - 1].index - arr2[len - 2].index);

        let val2 =
          (arr[i].key - arr2[len - 1].key) /
          (arr[i].index - arr2[len - 1].index);

        if (val1 <= val2) {
          arr2.pop();
          len--;
        } else {
          break;
        }
      }
      arr2.push(arr[i]);
      len++;
      ans = Math.max(ans, arr2[len - 1].index - arr2[len - 2].index);
    }
    console.log(ans);
  }
};
