module VgaController (clock, hsync, vsync, fbuffer_addr, buffer_enable);
  input clock;
  output hsync;
  output vsync;
  output buffer_enable;
  output [15:0] fbuffer_addr;
  reg [9:0] counterx;
  reg [9:0] countery;
  always @(posedge clock) counterx <= (counter == 799) ? 0 : counterx + 1;
  always @(posedge clock) if(counterx == 799) countery <= (countery == 524) ? 0 : countery + 1;
  assign vsync = (countery >= 490) && (countery <= 491);
  assign hsync = (counterx >= 656) && (counterx <= 751);
  assign buffer_enable = (counterx < 640) && (countery < 480);
  assign fbuffer_addr = counterx + countery * 480;
endmodule
