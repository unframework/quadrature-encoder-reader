#define PIN_QUAD_A 2
#define PIN_QUAD_B 3

int counter = 0;
int lastCounter = 0;

void handlePinChange() {
    // use constant-time logic as much as possible
    const int valA = digitalRead(PIN_QUAD_A);
    const int valB = digitalRead(PIN_QUAD_B);

    const int direction = valA == valB ? 1 : -1;

    counter += direction;
}

void setup() {
    Serial.begin(9600); // for serial plotter test output

    pinMode(PIN_QUAD_A, INPUT);
    pinMode(PIN_QUAD_B, INPUT);

    attachInterrupt(digitalPinToInterrupt(2), handlePinChange, CHANGE);
}

void loop() {
    delay(1);

    if (lastCounter != counter) {
        Serial.println(counter);
        lastCounter = counter;
    }
}
