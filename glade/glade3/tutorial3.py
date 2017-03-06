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
		self.builder.add_from_file("tutorial3.glade")
		self.builder.connect_signals(self)
		self.window = self.builder.get_object("window")
		self.aboutdialog = self.builder.get_object("aboutdialog")
		self.statusbar = self.builder.get_object("statusbar")
		self.context_id = self.statusbar.get_context_id("status")
		self.textview = self.builder.get_object("text_view")
		self.notebook = self.builder.get_object("notebook1")
		#self.textbuffer = self.textview.get_buffer()
		self.window.show()
		self.status_count = 0

	def on_window_destroy(self, widget, data=None):
		print "quit with cancel"
		Gtk.main_quit()

	def on_gtk_new_activate(self, menutiem, data=None):
		print("File New selected")
		self.label1 = Gtk.Label('Page '+ str(self.notebook.get_n_pages()+1))
		self.label2 = Gtk.Label('Hello World')
		self.label2.show()
		self.notebook.append_page(self.label2, self.label1)
	
	def on_notebook1_switch_page(self, notebook, page, page_num, data=None):
		self.tab = notebook.get_nth_page(page_num)
		self.label = notebook.get_tab_label(self.tab).get_label()
		self.message_id = self.statusbar.push(0, self.label)

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
