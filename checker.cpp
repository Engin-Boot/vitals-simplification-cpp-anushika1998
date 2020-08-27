#include <assert.h>

const float[] bpmLimits={70,150};
const float[] respLimits={30,95};
const float[] spo2Limits={90, INT_MAX};

bool isVitalOk(float val, float [] limits){
  return val > limits[0] && val < limits[1];
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  return isVitalOk(bpm,bpmLimits) || isVitalOk(spo2,spo2Limits) || isVitalOk(respRate,respLimits);
}

int main() {
  assert(isVitalOk(11,bpmLimits) == false);
  assert(isVitalOk(440, spo2Limits) == true);
  assert(isVitalOk(2324, respLimits) == false);
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
