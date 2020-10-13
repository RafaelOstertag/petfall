A game similar to MS-DOS Pitfall for Commodore PET. Only PET models
30xx and 40xx are supported.

Build Requirements
---

* [cc65](https://github.com/cc65/cc65)
* [VICE](https://vice-emu.sourceforge.io/)

Building
---

Checkout repository, and call

	make full

This will create the executable `petfall`, as well as `petfall.d64`, a
disk file that can be used for instance with VICE.

Running
---

Assuming you use VICE, attach `petfall.d64` as disk image to drive #8,
then type

	LOAD"PETFALL",8
	RUN
	
