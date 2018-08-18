#include <Gamebuino-Meta.h>


const char* entriesEoff[] = {
  "Enter Edit mode",
  "Clear grid",
  "Randomize grid",
  "Return",
};
const char* entriesEon[] = {
  "Quit Edit mode",
  "Clear grid",
  "Randomize grid",
  "Return",
};
bool Emode = false;



Color colors[10] = {BLACK, BLUE, LIGHTBLUE, LIGHTGREEN, GREEN, BEIGE, YELLOW, ORANGE, RED, WHITE};

bool Play = true;
uint8_t grid[80][64] ;
unsigned long time = 0 ;
uint16_t temp = 0 ;

void setup() {
  for (int x = 0; x < 80; x++) {
    for (int y = 0; y < 64; y++) {
      grid[x][y] = random(0, 2);
    }
  }
  gb.begin();

}

void loop() {
  while (!gb.update());
  if (gb.buttons.pressed(BUTTON_A)) {
    if (Emode) {

    } else {
      if (Play) {
        const char* text = "Paused" ;
        gb.gui.popup( text,  25);
        Play = false;
      } else {
        const char* text = "Playing" ;
        gb.gui.popup( text,  25);
        Play = true;
      }
    }

  }
  if (gb.buttons.pressed(BUTTON_HOME)) {
    Play = false;
    uint8_t entry;
    if (Emode) {
      entry = gb.gui.menu("--Menu--", entriesEon, 4);
      if (entry == 0) {
        Emode = 0;
        const char* text = "Emode OFF, Playing" ;
        gb.gui.popup( text,  25);
      }
    } else {
      entry = gb.gui.menu("--Menu--", entriesEoff, 4);
      if (entry == 0) {
        Emode = 1;
        const char* text = "Edit mode ON" ;
        gb.gui.popup( text,  25);
      }
    }

    switch (entry) {
      case 1 :
        for (int x = 0; x < 80; x++) {
          for (int y = 0; y < 64; y++) {
            grid[x][y] = 0;
            const char* text = "Cleared !" ;
            gb.gui.popup( text,  25);
          }
        }
        break;
      case 2 :
        for (int x = 0; x < 80; x++) {
          for (int y = 0; y < 64; y++) {
            grid[x][y] = random(0, 2);
            const char* text = "Randomized !" ;
            gb.gui.popup( text,  25);
          }
        }
        break;
    }
    Play = true;
  }
  gb.display.clear();
  if (Play && !Emode) {
    updateG();
  }
  for (int x = 0; x < 80; x++) {
    for (int y = 0; y < 64; y++) {
      gb.display.setColor(colors[grid[x][y]]);
      gb.display.drawPixel(x, y);
    }
  }

  /*
    // debug hud
    uint16_t ram = gb.getFreeRam();
    uint8_t load = gb.getCpuLoad();
    if (load > 85) {
      gb.display.setColor(RED);
    } else {
      gb.display.setColor(LIGHTBLUE);
    }

    gb.display.fillRect(0, 0, 29, 7);
    gb.display.fillRect(43, 0, 40 , 7);
    gb.display.setColor(GREEN);
    gb.display.fillRect(31, 0, 9 , 7);
    gb.display.setColor(WHITE);

    gb.display.setCursor(1, 1);
    gb.display.setFontSize(1);
    gb.display.print("CPU:");
    gb.display.print(load);
    gb.display.println("%");


    gb.display.setCursor(32, 1);
    temp = millis() - time ;
    gb.display.print(1000 / temp);
    time = millis();
    gb.display.setCursor(44, 1);

    gb.display.print("RAM:");
    gb.display.println(ram);
  */

}
