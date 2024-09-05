function findOptimalFridge(n) {
    let minSurfaceArea = 2 * (n + n + n);
     let bestA = 1, bestB = 1, bestC = n;

    for (let a = 1; a * a * a <= n; ++a) {
        if (n % a === 0) {
            for (let b = a; a * b * b <= n; ++b) {
                if (n % (a * b) === 0) {
                    let c = n / (a * b);
                     let surfaceArea = 2 * (a * b + a * c + b * c);
                      if (surfaceArea < minSurfaceArea) {
                        minSurfaceArea = surfaceArea;
                        bestA = a;
                        bestB = b;
                        bestC = c;
                    }
                }
            }
        }
    }

    let dims = [bestA, bestB, bestC].sort((x, y) => x - y);
     return dims;
}

// Чтение ввода из стандартного потока ввода
const readline = require('readline');
 const rl = readline.createInterface({
    input: process.stdin,
     output: process.stdout
});

 rl.on('line', (line) => {
    const n = parseInt(line.trim(), 10);
     const result = findOptimalFridge(n);
      console.log(result.join(' '));
       rl.close();
});
