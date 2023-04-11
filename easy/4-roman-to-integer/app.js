// Roman object
const roman = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000
};

const romanToInt = (s) => {
    let container = 0;
    
    for(let i = 0; i < s.length; i++) {
        if(s[i] === "I" && s[i+1] === "V") {
            container += 4;
            i++;
        } else if (s[i] === "I" && s[i+1] === "X") {
            container += 9;
            i++;
        } else if (s[i] === "X" && s[i+1] === "L") {
            container += 40;
            i++;
        } else if (s[i] === "X" && s[i+1] === "C") {
            container += 90;
            i++;
        } else if(s[i] === "C" && s[i+1] === "D") {
            container += 400;
            i++;
        } else if (s[i] === "C" && s[i+1] === "M") {
            container += 900;
            i++;
        } else {
            container += roman[s[i]];
        }
    }

    return container;
};

console.log(romanToInt("IV"));