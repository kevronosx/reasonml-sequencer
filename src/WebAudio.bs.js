// Generated by BUCKLESCRIPT VERSION 3.1.5, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");

var audioContext = new AudioContext();

function createSchedule(callback) {
  var beatTime = [0];
  var beatLength = 60 / 120 / 1;
  var onTimeout = function () {
    var targetTime = audioContext.currentTime + 0.2;
    while(beatTime[0] < targetTime) {
      Curry._2(callback, beatTime, beatLength);
      beatTime[0] += beatLength;
    };
    setTimeout(onTimeout, 100);
    return /* () */0;
  };
  return onTimeout(/* () */0);
}

exports.audioContext = audioContext;
exports.createSchedule = createSchedule;
/* audioContext Not a pure module */
