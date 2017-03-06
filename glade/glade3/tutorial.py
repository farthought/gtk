#!/usr/bin/env python

try:
	import sys
	import gi
	gi.require_version('Gtk', '3.0')
	from gi.repository import Gtk
except:
	print('GI not available')
	sys.exit(1)
try:
	import math
except:
	print("Math is not availabe")
	sys.exit(1)

class TutorialTextEdit:
	def __init__(self):
		self.builder = Gtk.Builder()
		self.builder.add_from_file("tutorial2.glade")
		self.builder.connect_signals(self)
		self.window = self.builder.get_object("window")
		self.aboutdialog = self.builder.get_object("aboutdialog")
		self.statusbar = self.builder.get_object("statusbar")
		self.context_id = self.statusbar.get_context_id("status")
		self.textview = self.builder.get_object("text_view")
		#self.textbuffer = self.textview.get_buffer()
		self.window.show()
		self.status_count = 0

	def on_window_destroy(self, widget, data=None):
		print "quit with cancel"
		Gtk.main_quit()

	def on_sfm_button_clicked(self, button, data=None):
		self.entry1 = self.builder.get_object("entry1")
		self.entry2 = self.builder.get_object("entry2")
		self.result = self.builder.get_object("result")
		self.sfm = float(self.entry1.get_text())
		self.diameter = float(self.entry2.get_text())
		self.rpm = str(int(self.sfm*((12/math.pi)/self.diameter)))

		print "calculate rpm clicked"
		self.result.set_text(self.rpm)

	def on_gtk_quit_activate(self, menuitem, data=None):
		print "quit from menu"
		Gtk.main_quit()

	def on_push_status_activate(self, menuitem, data=None):
		self.status_count += 1
		self.statusbar.push(self.context_id, "Message number %s" %
				str(self.status_count))

	def on_pop_status_activate(self, menuitem, data=None):
		self.status_count -= 1
		self.statusbar.pop(self.context_id)
    
	def on_clear_status_activate(self, menuitem, data=None):
		while (self.status_count > 0):
			self.statusbar.pop(self.context_id)
			self.status_count -= 1

	def on_gtk_about_activate(self, menuitem, data=None):
		print "help about selected"
		self.response = self.aboutdialog.run()
		self.aboutdialog.hide()

if __name__ == "__main__":
	editor = TutorialTextEdit()
	Gtk.main()
