#include <Gamebuino-Meta.h>


uint8_t grid[80][64] ;
unsigned long time = 0 ;
uint16_t temp = 0 ;

void setup() {
  for(int x=0;x<80;x++) {
    for(int y=0;y<64;y++) {
      grid[x][y] = random(0,2);
    }
  }
  gb.begin();
  
}

void loop() {
  while (!gb.update());
  updateG();
  gb.display.clear();
  gb.display.setColor(WHITE);
  for(int x=0;x<80;x++) {
    for(int y=0;y<64;y++) {
      if(grid[x][y]) gb.display.drawPixel(x, y);
    }
  }





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


}
