/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let curVal = init;
    
    function increment() {
        return ++curVal;
    }

    function decrement() {
        return --curVal;
    }

    function reset() {
        return curVal = init;
    }

    return { increment, decrement, reset };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */