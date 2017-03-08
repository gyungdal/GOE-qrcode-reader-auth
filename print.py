import os
import cups
conn = cups.Connection()
printers = conn.getPrinters()
printer_name = printers.keys()[0]
cups.setUser('pi')
conn.printFile(printer_name, os.path.abspath('utf.txt'), "test",{'orientation-requested':'4', 'scaling' : '70'})
