/**
 * @param {number[][]} coordinates
 * @return {boolean}
 */
var checkStraightLine = function(cor) {
    if(cor.length==2) return true;
    let delx = (cor[1][0]-cor[0][0]);
    let dely = (cor[1][1]-cor[0][1]);
    let slope = dely/delx;
    let isVertical = delx == 0 ? true :false;
    
    
    for(let i=2;i<cor.length;i++){
        if(isVertical && (cor[i][0]-cor[i-1][0] != 0)) return false;
        else if(!isVertical && (cor[i][1]-cor[i-1][1])/(cor[i][0]-cor[i-1][0])!=slope) return false;
    }
    return true;
};