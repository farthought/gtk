#!/usr/bin/env python

import sys
import gtk

class Caculator:
	def __init__(self):
		self.builder = gtk.Builder()
		self.builder.add_from_file("caculator.glade")
		self.builder.connect_signals(self)
		self.window = self.builder.get_object("main_window")
		self.entry = self.builder.get_object("input_entry")
		self.window.show()
		self.count = 0
		self.nn = 0
		self.mm = 0
		self.s = 0
		self.first = True
		self.have_dot = False
		self.have_result = False
		self.number = ""
	
	def on_main_window_destroy(self, widget, data = None):
		gtk.main_quit()

	def clear_all(self):
		self.entry.set_text("")
		self.nn = 0
		self.mm = 0
		self.s = 0
		self.count = 0
		self.first = True
		self.have_dot = False
		self.have_result = False
		self.number = ""
	def on_num_clicked(self, button, user_data=None):
		if(self.have_result):
			self.clear_all()
		if(self.count == 6):
			return
		self.count = self.count +1
		num = button.get_label()
		self.number = self.number + "%s" % num
		if(self.first):
			self.nn = float(self.number)
		else:
			self.mm = float(self.number)
		self.entry.set_text(self.number)
	
	def on_dot_button_clicked(self, button, user_data=None):
		if(self.have_result):
			self.clear_all()
		if(self.have_dot == False):
			self.have_dot = True
			self.number = self.number + "."
			self.entry.set_text(self.number) 
	
	def on_clear_button_clicked(self, button, user_data):
		self.clear_all()
	
	def compare(self, argument):
		switcher = {
				"+":1,
				"-":2,
				"*":3,
				"/":4,}
		return switcher.get(argument, 0)

	def on_suan_clicked(self, button, user_data=None):
		str = button.get_label()
		self.s = self.compare(str)
		self.entry.set_text("")
		self.first = False
		self.count = 0
		self.have_dot = False
		self.number = ""
    
	def compare2(self, argument):
		switcher2 = {
				1:'+',
				2:'-',
				3:'*',
				4:'/',
				}
		return switcher2.get(argument, '')

	def on_equal_button_clicked(self, button, user_data=None):
		ope = self.compare2(self.s)
		if(ope == '+'):
			numb = self.nn + self.mm
		elif (ope == '-'):
			numb = self.nn - self.mm
		elif (ope == '*'):
			numb = self.nn * self.mm
		else:
			numb = self.nn/self.mm
		numb = str(numb)
		self.entry.set_text(numb)
		self.have_result = True

if __name__ == "__main__":
	instance = Caculator()
	gtk.main()
