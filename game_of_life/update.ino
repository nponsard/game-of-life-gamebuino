void updateG() {
  uint8_t temp[80][64];
  uint8_t n ;
  for (int x = 0; x < 80; x++) {
    for (int y = 0; y < 64; y++) {
      n = neighbours(grid, x, y);
      temp[x][y] = 1;
      if (grid[x][y] > 0) {
        if (n > 3 || n < 2) {
          temp[x][y] = 0;
        }
      } else {
        if (n != 3) {
          temp[x][y] = 0;
        }
      }
    }
  }
  for (int x = 0; x < 80; x++) {
    for (int y = 0; y < 64; y++) {
      grid[x][y] = temp[x][y];

    }
  }



}

uint8_t neighbours(uint8_t grid[80][64], uint16_t x, uint16_t y) {
  uint8_t sum = 0;
  uint16_t w = (sizeof(grid) / sizeof(*grid));
  uint16_t h = (sizeof(grid[0]) / sizeof(*grid[0]));
  if (x != 0) {
    if (grid[x - 1][y]) sum += 1;
    if (y != h - 1) {
      if (grid[x - 1][y + 1]) sum += 1;
    }
  }
  if (y != 0) {
    if (grid[x][y - 1]) sum += 1;
    if (x != 0) {
      if (grid[x - 1][y - 1]) sum += 1;
    }
    if (x != w - 1) {
      if (grid[x + 1][y - 1]) sum += 1;
    }
  }
  if (x != w - 1) {
    if (grid[x + 1][y]) sum += 1;
  }
  if (y != h - 1) {
    if (grid[x][y + 1]) sum += 1;
    if (x != w - 1) {
      if (grid[x + 1][y + 1]) sum += 1;
    }
  }
  return sum;

}

