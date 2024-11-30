function xor64bit(a, b) {
    a = BigInt(a);
    b = BigInt(b);
    
    var result = a ^ b;

    return result;
}

function asciiToHex(str) {
    var hex = '';
    var acode = 'a'.charCodeAt(0);
    for(var i = 0; i < str.length; i++) {
        var charCode = (str.charCodeAt(i)-acode).toString(16);
        hex += charCode.length < 2 ? '0' + charCode : charCode;
    }
    return hex;
}

function hashCode(str) {
    let hash = 0;
    for (let i = 0, len = str.length; i < len; i++) {
        let chr = str.charCodeAt(i);
        hash = (hash << 5) - hash + chr;
        hash |= 0; // Convert to 32bit integer
    }
    return hash;
}

function attemptDecodeToken(password) {
  var encoded = BigInt("164423740064328");
  var rslt = "60e9401f-15a8-448f-ac4a-" + xor64bit(BigInt("0x"+asciiToHex(password)),encoded).toString(16);
  console.log("decoded token attempt " + rslt);
  return rslt;
}
