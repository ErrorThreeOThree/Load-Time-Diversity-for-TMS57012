ESM error: esm->Stat3 ist 0x00000008 statt 0. 
Folge https://e2e.ti.com/support/microcontrollers/hercules/f/312/t/277650?Startup-problem-ESM-Group-3-error-in-sys-startup-c
setze esm->Stat3 auf 0 indem ich 0xffffffffh schreibe

Ich muss die Stacks umsetzen, momentan conflicten die loader stacks mit dem user program.
