#!/usr/bin/env python

try:
	import sys
	import gi
	gi.require_version('Gtk', '3.0')
	from gi.repository import Gtk
except:
	print('GI not available')
	sys.exit(1)

class Buglump:
	def __init__(self):
		self.builder = Gtk.Builder()
		self.builder.add_from_file("combox.glade")
		self.builder.connect_signals(self)
		self.window = self.builder.get_object("window1")
		self.liststore = Gtk.ListStore(int, str)
		self.liststore.append([0, "Select an Item:"])
		for i in range(1, 6):
			self.liststore.append([i, "Row "+str(i)])
		self.combobox = self.builder.get_object("combobox1")
		self.combobox.set_model(self.liststore)
		self.cell = Gtk.CellRendererText()
		self.combobox.pack_start(self.cell, True)
		self.combobox.add_attribute(self.cell, 'text', 1)
		self.combobox.set_active(0)
		self.window.show()

	def on_window1_destroy(self, widget, data=None):
		print "quit with cancel"
		Gtk.main_quit()

	def on_combobox1_changed(self, widget, data=None):
		self.index = widget.get_active()
		self.model = widget.get_model()
		self.item = self.model[self.index][1]
		print ("ComboBox Atcive Text is %s") % self.item
		print ("ComboBox Active Index is %s") % self.index
		self.builder.get_object("label1").set_text(self.item)

if __name__ == "__main__":
	main = Buglump()
	Gtk.main()
