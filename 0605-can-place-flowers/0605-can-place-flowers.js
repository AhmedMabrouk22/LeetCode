/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function(flowerbed, n) {
    for(let i = 0 ; i < flowerbed.length ; ++i) 
    {
        if (flowerbed[i] === 0)
        {
            let l = i === 0 || flowerbed[i-1] === 0;
            let r = i === flowerbed.length -1 || flowerbed[i+1] === 0;

            if (l && r)
            {
                --n;
                flowerbed[i] = 1;
            }

            if (n <= 0)
                return true;
        }
    }
    return n <= 0;
};