import processing.serial.*;

Serial puerto;

void setup() {
  size(400, 200);
  puerto = new Serial(this, "COM3", 9600); // Ajusta el nombre del puerto COM según tu configuración
}

void draw() {
  background(255);

  // Dibuja las entradas (pulsadores)
  fill(checkInputState(2) ? color(0, 255, 0) : color(255, 0, 0));
  rect(50, 50, 50, 50);

  // Dibuja las salidas (LEDs)
  fill(checkOutputState(3) ? color(0, 255, 0) : color(255, 0, 0));
  rect(250, 50, 50, 50);
}

void mousePressed() {
  // Detecta clic en la salida y envía el comando a Arduino
  if (mouseX > 250 && mouseX < 300 && mouseY > 50 && mouseY < 100) {
    puerto.write("TOGGLE_OUTPUT_3\n");
  }
}

void keyPressed() {
  // Detecta tecla presionada y envía el comando a Arduino
  if (key == 'a' || key == 'A') {
    puerto.write("TOGGLE_INPUT_2\n");
  }
}

boolean checkInputState(int pin) {
  // Solicita el estado del pin de entrada a Arduino
  puerto.write("CHECK_INPUT_" + pin + "\n");

  // Lee la respuesta de Arduino y actualiza el estado
  if (puerto.available() > 0) {
    return puerto.readStringUntil('\n').trim().equals("HIGH");
  }

  return false;
}

boolean checkOutputState(int pin) {
  // Solicita el estado del pin de salida a Arduino
  puerto.write("CHECK_OUTPUT_" + pin + "\n");

  // Lee la respuesta de Arduino y actualiza el estado
  if (puerto.available() > 0) {
    return puerto.readStringUntil('\n').trim().equals("HIGH");
  }

  return false;
}
