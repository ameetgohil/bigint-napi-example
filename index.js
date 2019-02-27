const dut = require('./build/Release/dut.node');
console.log('sldkfs');

console.log(dut.get());
dut.set(300n);
console.log(dut.get());
