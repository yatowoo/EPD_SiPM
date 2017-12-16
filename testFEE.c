#include "EPDFEE.h"

int main(int argc, char *argv[])
{
  // uint64_t owaddr = 0xFF00000007F6043AULL; // first EPD board
  // uint64_t owaddr = 0xE700000032C03B3AULL; // EPD FEE #7 (testing/development for gain change, 4/17)
  // uint64_t owaddr = 0x8D00000032C3343AULL; // EPD FEE #9 (testing/development for gain change, 4/17)
  uint64_t owaddr = 0x3800000007EA673AULL; // DS2413 adapter #1 for new FEE testing
  struct linkusb_dev linkusb;
  int k;
  uint64_t serial;
  int swaddr = 0; // address on the switch on this FEE (or can loop over a set of them)

  if (linkusb_open(&linkusb, 0))
    return -1; // error messages in linkusb_open

  EPD_connect_FEE(&linkusb, owaddr, swaddr); // connect to FEE at switch address 0
  DS28CM00_read(&linkusb, owaddr, &serial);
  printf("FEE %d serial number: 0x%016llx\n", swaddr, serial);

  //EPD quick first tests
  for (k = 0; k < 16; k++)
    EPD_set_voltage(&linkusb, owaddr, k, 55.0); //hacked for offset test 7/2 put it back!!  56.5);//57);
  EPD_set_vslope(&linkusb, owaddr, 0.054);
  for (k = 0; k < 16; k++)
    EPD_set_ped(&linkusb, owaddr, k, 0);

  for (k = 0; k < 16; k++)
  {
    printf("channel %2d: regulator control voltage = %5.3lf V, current monitor = %6.3lf uA\n",
           k, EPD_get_rmon(&linkusb, owaddr, k), EPD_get_imon(&linkusb, owaddr, k));
  }
  printf("bias compensation voltage (applies to all channels) = %.3lf V\n", EPD_get_vcomp(&linkusb, owaddr));
  printf("pedestal compensation voltage (applies to all channels) = %.3lf V\n", EPD_get_vpedcomp(&linkusb, owaddr));

  EPD_disconnect_FEE(&linkusb, owaddr);
  linkusb_close(&linkusb);
  return 0;
}