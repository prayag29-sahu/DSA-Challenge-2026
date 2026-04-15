const maxSubArray = (arr) => {
    let curr = arr[0];
    let max = arr[0];
    let n = arr.length;
    
    for (let i = 1; i < n; ++i){
        curr = Math.max(arr[i], curr + arr[i]);
        max = Math.max(curr, max);
    }
    return max;
}

let arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4];
console.log(maxSubArray(arr))