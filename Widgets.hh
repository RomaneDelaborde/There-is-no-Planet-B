#pragma once

#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/button.h>
#include <string>
#include <iostream>

std::string split_name_image(std::string name);

class Image: public Gtk::Image {
		
	public:
		Image(const std::string & file) : Gtk::Image(file) {name = file;}
		Image() : Gtk::Image() {}
		Image& operator=(const Image& image);
		std::string get_name() const {return name;}
		
	private:
		std::string name;
};

class Bouton : public Gtk::Button {
	protected:
		std::string name;
	
	public:
		Bouton(const Glib::ustring& label, bool mnemonic = false) : Gtk::Button(label, false), name("") {set_can_focus(false);}
		Bouton(Image& image) : Gtk::Button(), name(image.get_name()) {set_image(image); set_can_focus(false);}
		virtual std::string get_name() const = 0;
};


class BoutonTexte: public Bouton {
	public:
		BoutonTexte(const Glib::ustring& label) : Bouton(label) {};
		std::string get_name() const {return "no name";};
};


class BoutonCarte: public Bouton {
	public:
		BoutonCarte(Image& image, int c = -1, int l = -1);
	
		void zoom_Image() const;
		std::string get_name() const {return name_tiny_image;};
		int get_column() const {return column_coordinate;};
		int get_line() const {return line_coordinate;};
		void set_column(int col) {column_coordinate = col;};
		void set_line(int line) {line_coordinate = line;};

		bool operator== (std::string name) {return name_tiny_image == name;};

	private:
		std::string name_tiny_image;
		std::string name_big_image;
		int column_coordinate;
		int line_coordinate;
};

class BoutonAccueil: public Bouton {
	public:
		BoutonAccueil(Image& image) : Bouton(image) {set_relief(Gtk::RELIEF_NONE);};
		std::string get_name() const {return name;};
};

/*
class Fin {
protected:
	
	
	
};


class FinGagnante : public Fin {
	
	
};


class FinPerdante : public Fin {
	
	
};*/
