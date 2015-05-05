int REF_3V3 = A0;
int LINE1 = A1;
int LINE2 = A2;

const int numberOfReadings = 100;

int LINE1_Readings[numberOfReadings];
int LINE2_Readings[numberOfReadings];
int REF_Readings[numberOfReadings];

double LINE1_avg;
double LINE2_avg;
double REF_avg;

int LINE1_max;
int LINE2_max;
int REF_max;

int LINE1_min;
int LINE2_min;
int REF_min;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting");
}

void loop() {
  for (int K = 0; K < numberOfReadings; K++) {
    ReadPins(K);
  }
  GetAVG();
  GetMinMax();
  Serial.print("{\"MIN\":{\"LINE1\":" + (String)LINE1_min + ",\"LINE2\":" + (String)LINE2_min + ",\"REF\":" + (String)REF_min + "}");
  Serial.print(",\"MAX\":{\"LINE1\":" + (String)LINE1_max + ",\"LINE2\":" + (String)LINE2_max + ",\"REF\":" + (String)REF_max + "}");
  Serial.println(",\"AVG\":{\"LINE1\":" + (String)LINE1_avg + ",\"LINE2\":" + (String)LINE2_avg + ",\"REF\":" + (String)REF_avg + "}}");
}


void ReadPins(int index) {
  LINE1_Readings[index] = analogRead(LINE1);
  LINE2_Readings[index] = analogRead(LINE1);
  REF_Readings[index] = analogRead(REF_3V3);
}

void GetAVG() {
  LINE1_avg = 0;
  LINE2_avg = 0;
  REF_avg = 0;

  for (int K = 0; K < numberOfReadings; K++) {
    LINE1_avg += LINE1_Readings[K];
    LINE2_avg += LINE2_Readings[K];
    REF_avg += REF_Readings[K];
  }

  LINE1_avg = LINE1_avg / numberOfReadings;
  LINE2_avg = LINE2_avg / numberOfReadings;
  REF_avg = REF_avg / numberOfReadings;

}

void GetMinMax() {
  LINE1_max = 0;
  LINE2_max = 0;
  REF_max = 0;

  LINE1_min = 0;
  LINE2_min = 0;
  REF_min = 0;

  for (int K = 0; K < numberOfReadings; K++) {
    if (LINE1_Readings[K] > LINE1_max) LINE1_max = LINE1_Readings[K];
    if (LINE2_Readings[K] > LINE2_max) LINE2_max = LINE2_Readings[K];
    if (REF_Readings[K] > REF_max) REF_max = REF_Readings[K];

    if (LINE1_Readings[K] < LINE1_min) LINE1_min = LINE1_Readings[K];
    if (LINE2_Readings[K] < LINE2_min) LINE2_min = LINE2_Readings[K];
    if (REF_Readings[K] < REF_min) REF_min = REF_Readings[K];
  }

}

