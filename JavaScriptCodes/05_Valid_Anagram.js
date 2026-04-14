function valid_anagram(s, t) {
    if (s.length != t.length) return false;
    let count = Array(26).fill(0);

    for (let i = 0; i < s.length; i++){
        count[s.charCodeAt(i) - 97]++;
        count[t.charCodeAt(i) - 97]--;
    }

    return count.every(x => x === 0);

}

console.log(valid_anagram("anagram", "margana"))