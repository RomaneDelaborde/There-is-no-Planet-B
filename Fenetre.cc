#include "Fenetre.hh"
#include "jeu.hh" 
 
//fonction venant de stackoverflow
bool is_number(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}
  

FenetreJeu::FenetreJeu() : Gtk::Window(), white_0101("Images/white.jpg"), white_1201("Images/white.jpg"), white_2301("Images/white.jpg"),
	white_3401("Images/white.jpg"), white_0112("Images/white.jpg"), white_1212("Images/white.jpg"),
	white_2312("Images/white.jpg"), white_3412("Images/white.jpg"), inventory1("Images/white_inventory.jpg"),
	inventory2("Images/white_inventory.jpg"), inventory3("Images/white_inventory.jpg"), inventory4("Images/white_inventory.jpg"),
	inventory5("Images/white_inventory.jpg"), inventory6("Images/white_inventory.jpg"), inventory7("Images/white_inventory.jpg"),
	inventory8("Images/white_inventory.jpg"), about_image("Images/about.png"), rules("Images/rules.png"),
	annonce_radio("Images/annonce_radio.jpg"), bibliotheque("Images/bibliotheque.jpg"), boite_chocolat("Images/boite_chocolat.jpg"),
	boite_gants("Images/boite_gants.jpg"), boite_outils("Images/boite_outils.jpg"), boss_assomme("Images/boss_assomme.jpg"),
	boss_enerve("Images/boss_enerve.jpg"), boss_mort("Images/boss_mort.jpg"), bureau("Images/bureau.jpg"),
	certificat("Images/certificat.jpg"), coffre_fort("Images/coffre_fort.jpg"), dessin_mur("Images/dessin_mur.jpg"),
	dessin_recto("Images/dessin_recto.jpg"), dessin_sol("Images/dessin_sol.jpg"), dessin_verso("Images/dessin_verso.jpg"),
	dialogue_patron("Images/dialogue_patron.jpg"), frequences("Images/frequences.jpg"), garage("Images/garage.jpg"),
	non_revelation("Images/non_revelation.jpg"), planetes("Images/planetes.jpg"), porte_cachee("Images/porte_cachee.jpg"),
	pressing("Images/pressing.jpg"), radio("Images/radio.jpg"), retroviseur("Images/retroviseur.jpg"),
	revelation("Images/revelation.jpg"), table_chevet("Images/table_chevet.jpg"), ticket_dore("Images/ticket_dore.jpg"),
	tiroir("Images/tiroir.jpg"), voiture("Images/voiture.jpg"), zoom_livres("Images/zoom_livres.jpg"),
	boss_o("Images/boss_o.jpg"), certificat_o("Images/certificat_o.jpg"), cesar("Images/cesar.jpg"),
	epingle_cheveux("Images/epingle_cheveux.jpg"), morceau1("Images/morceau1.jpg"), morceau2("Images/morceau2.jpg"),
	pied_biche("Images/pied_biche.jpg"), porte_cachee_o("Images/porte_cachee_o.jpg"), porte_electronique("Images/porte_electronique.jpg"),
	revolver("Images/revolver.jpg"), ticket_dore_o("Images/ticket_dore_o.jpg"),
	bouton_0101(white_0101, 0, 0), bouton_1201(white_1201, 1, 0), bouton_2301(white_2301, 2, 0), bouton_3401(white_3401, 3, 0),
	bouton_0112(white_0112, 0, 1), bouton_1212(white_1212, 1, 1), bouton_2312(white_2312, 2, 1), bouton_3412(white_3412, 3, 1),
	bouton_inventory1(inventory1, 0, 1), bouton_inventory2(inventory2, 1, 1), bouton_inventory3(inventory3, 2, 1),
	bouton_inventory4(inventory4, 3, 1), bouton_inventory5(inventory5, 4, 1), bouton_inventory6(inventory6, 5, 1),
	bouton_inventory7(inventory7, 6, 1), bouton_inventory8(inventory8, 7, 1), bouton_annonce_radio(annonce_radio),
	bouton_bibliotheque(bibliotheque), bouton_boite_chocolat(boite_chocolat), bouton_boite_gants(boite_gants), bouton_boite_outils(boite_outils),
	bouton_boss_assomme(boss_assomme), bouton_boss_enerve(boss_enerve), bouton_boss_mort(boss_mort), bouton_bureau(bureau),
	bouton_certificat(certificat), bouton_coffre_fort(coffre_fort), bouton_dessin_mur(dessin_mur), bouton_dessin_recto(dessin_recto),
	bouton_dessin_sol(dessin_sol), bouton_dessin_verso(dessin_verso), bouton_dialogue_patron(dialogue_patron), bouton_frequences(frequences),
	bouton_garage(garage), bouton_non_revelation(non_revelation), bouton_planetes(planetes), bouton_porte_cachee(porte_cachee),
	bouton_pressing(pressing), bouton_radio(radio), bouton_retroviseur(retroviseur), bouton_revelation(revelation), bouton_table_chevet(table_chevet),
	bouton_ticket_dore(ticket_dore), bouton_tiroir(tiroir), bouton_voiture(voiture), bouton_zoom_livres(zoom_livres), bouton_boss_o(boss_o),
	bouton_certificat_o(certificat_o), bouton_cesar(cesar), bouton_epingle_cheveux(epingle_cheveux), bouton_morceau1(morceau1),
	bouton_morceau2(morceau2), bouton_pied_biche(pied_biche), bouton_porte_cachee_o(porte_cachee_o), bouton_porte_electronique(porte_electronique),
	bouton_revolver(revolver), bouton_ticket_dore_o(ticket_dore_o),
	combinaisons("Saisir une combinaison d'objets"), reponse_enigme("Saisir la réponse à une énigme"),
	tirer_carte_1("Saisir le numéro de la carte à tirer"), tirer_carte_2("(si vous en avez le droit)"),
	objet_1("objet n°1"), objet_2("objet n°2"), id_enigme("n° énigme"), reponse_enigme_l("réponse"), carte_num("n° carte"),
	separator1(Gtk::ORIENTATION_HORIZONTAL), separator2(Gtk::ORIENTATION_HORIZONTAL), separator3() {
	 
	Game = new Jeu(*this);
	  
	set_title("There is no Planet B");
	set_border_width(20);
	set_position(Gtk::WIN_POS_CENTER);
	
	table_big = new Gtk::Table(4, 1);
	add(*table_big);
	 
	init_allBoutonCartes();
	init_allBoutonObjets();
	init_table_zones_texte();
	init_table_images();
	init_table_inventory();
	
	show_all();
}

//Initialisation du vecteur de Cartes (toutes les cartes du Jeu, affichees sur le tableau du milieu)
void FenetreJeu::init_allBoutonCartes() {
	allBoutonCartes.push_back(&bouton_annonce_radio); allBoutonCartes.push_back(&bouton_bibliotheque);
	allBoutonCartes.push_back(&bouton_boite_chocolat); allBoutonCartes.push_back(&bouton_boite_gants);
	allBoutonCartes.push_back(&bouton_boite_outils); allBoutonCartes.push_back(&bouton_boss_assomme);
	allBoutonCartes.push_back(&bouton_boss_enerve); allBoutonCartes.push_back(&bouton_boss_mort);
	allBoutonCartes.push_back(&bouton_bureau); allBoutonCartes.push_back(&bouton_certificat);
	allBoutonCartes.push_back(&bouton_coffre_fort); allBoutonCartes.push_back(&bouton_dessin_mur);
	allBoutonCartes.push_back(&bouton_dessin_recto); allBoutonCartes.push_back(&bouton_dessin_sol);
	allBoutonCartes.push_back(&bouton_dessin_verso); allBoutonCartes.push_back(&bouton_dialogue_patron);
	allBoutonCartes.push_back(&bouton_frequences); allBoutonCartes.push_back(&bouton_garage);
	allBoutonCartes.push_back(&bouton_non_revelation); allBoutonCartes.push_back(&bouton_planetes);
	allBoutonCartes.push_back(&bouton_porte_cachee); allBoutonCartes.push_back(&bouton_pressing);
	allBoutonCartes.push_back(&bouton_radio); allBoutonCartes.push_back(&bouton_retroviseur);
	allBoutonCartes.push_back(&bouton_revelation); allBoutonCartes.push_back(&bouton_table_chevet);
	allBoutonCartes.push_back(&bouton_ticket_dore); allBoutonCartes.push_back(&bouton_tiroir);
	allBoutonCartes.push_back(&bouton_voiture); allBoutonCartes.push_back(&bouton_zoom_livres);
}
 
//Initialisation du vecteur d'Objets (toutes les Objets de l'inventaire du Jeu, affichees sur le tableau du bas)
void FenetreJeu::init_allBoutonObjets() {
	allBoutonObjets.push_back(&bouton_boss_o);
	allBoutonObjets.push_back(&bouton_certificat_o);
	allBoutonObjets.push_back(&bouton_cesar);
	allBoutonObjets.push_back(&bouton_epingle_cheveux);
	allBoutonObjets.push_back(&bouton_morceau1);
	allBoutonObjets.push_back(&bouton_morceau2);
	allBoutonObjets.push_back(&bouton_pied_biche);
	allBoutonObjets.push_back(&bouton_porte_cachee_o);
	allBoutonObjets.push_back(&bouton_porte_electronique);
	allBoutonObjets.push_back(&bouton_revolver);
	allBoutonObjets.push_back(&bouton_ticket_dore_o);
}


void FenetreJeu::init_table_zones_texte() {
	table_zones_texte = new Gtk::Table(7, 9);
	table_big->attach(*table_zones_texte, 0, 1, 0, 1);
	
	table_zones_texte->attach(combinaisons, 1, 2, 0, 1, Gtk::FILL, Gtk::FILL, 0, 5);
	table_zones_texte->attach(objet_1, 0, 1, 1, 2);
	table_zones_texte->attach(entry_objet_1, 1, 2, 1, 2, Gtk::FILL, Gtk::FILL, 0, 5);
	table_zones_texte->attach(objet_2, 0, 1, 2, 3);
	table_zones_texte->attach(entry_objet_2, 1, 2, 2, 3);
	table_zones_texte->attach(reponse_enigme, 3, 4, 0, 1, Gtk::FILL, Gtk::FILL, 0, 5);
	table_zones_texte->attach(id_enigme, 2, 3, 1, 2);
	table_zones_texte->attach(entry_id_enigme, 3, 4, 1, 2, Gtk::FILL, Gtk::FILL, 0, 5);
	table_zones_texte->attach(reponse_enigme_l, 2, 3, 2, 3);
	table_zones_texte->attach(entry_reponse_enigme_l, 3, 4, 2, 3);
	table_zones_texte->attach(tirer_carte_1, 5, 6, 0, 1);
	table_zones_texte->attach(tirer_carte_2, 5, 6, 1, 2, Gtk::FILL, Gtk::FILL, 0, 5);
	table_zones_texte->attach(carte_num, 4, 5, 2, 3);
	table_zones_texte->attach(entry_carte_num, 5, 6, 2, 3);
	
	//table_zones_texte->attach(separator2, 0, 9, 5, 6, Gtk::FILL, Gtk::FILL, 5, 20);
	
	bouton_about = new BoutonImage(about_image);
	table_zones_texte->attach(*bouton_about, 8, 9, 0, 2, Gtk::SHRINK);
	bouton_about->signal_clicked().connect(sigc::mem_fun(*this, &FenetreJeu::afficherApropos));
	
	bouton_rules = new BoutonImage(rules);
	table_zones_texte->attach(*bouton_rules, 7, 8, 0, 2, Gtk::SHRINK);
	bouton_rules->signal_clicked().connect(sigc::mem_fun(*this, &FenetreJeu::afficherRegles));
	
	bouton_combinaisons = new BoutonTexte("Envoyer");
	table_zones_texte->attach(*bouton_combinaisons, 1, 2, 4, 5,  Gtk::FILL, Gtk::FILL, 80, 5);
	bouton_combinaisons->signal_clicked().connect(sigc::mem_fun(*this, &FenetreJeu::requestCombinaison));
	
	bouton_enigme = new BoutonTexte("Envoyer");
	table_zones_texte->attach(*bouton_enigme, 3, 4, 4, 5, Gtk::FILL, Gtk::FILL, 80, 5);
	bouton_enigme->signal_clicked().connect(sigc::mem_fun(*this, &FenetreJeu::requestRepondreEnigme));
	
	bouton_carte = new BoutonTexte("Envoyer");
	table_zones_texte->attach(*bouton_carte, 5, 6, 4, 5, Gtk::FILL, Gtk::FILL, 80, 5);
	bouton_carte->signal_clicked().connect(sigc::mem_fun(*this, &FenetreJeu::requestCarte));
}

void FenetreJeu::init_table_images() {
	table_images = new Gtk::Table(2, 4);
	table_big->attach(*table_images, 0, 1, 1, 2);
	
	table_images->attach(bouton_0101, 0, 1, 0, 1);
	table_images->attach(bouton_1201, 1, 2, 0, 1);
	table_images->attach(bouton_2301, 2, 3, 0, 1);
	table_images->attach(bouton_3401, 3, 4, 0, 1);
	table_images->attach(bouton_0112, 0, 1, 1, 2);
	table_images->attach(bouton_1212, 1, 2, 1, 2);
	table_images->attach(bouton_2312, 2, 3, 1, 2);
	table_images->attach(bouton_3412, 3, 4, 1, 2);
}

void FenetreJeu::init_table_inventory() {
	table_inventory = new Gtk::Table(2, 8);
	table_big->attach(*table_inventory, 0, 1, 3, 4);
	table_big->attach(separator3, 0, 1, 2, 3, Gtk::FILL, Gtk::FILL, 5, 20);
	
	table_inventory->attach(bouton_inventory1, 0, 1, 1, 2);
	table_inventory->attach(bouton_inventory2, 1, 2, 1, 2);
	table_inventory->attach(bouton_inventory3, 2, 3, 1, 2);
	table_inventory->attach(bouton_inventory4, 3, 4, 1, 2);
	table_inventory->attach(bouton_inventory5, 4, 5, 1, 2);
	table_inventory->attach(bouton_inventory6, 5, 6, 1, 2);
	table_inventory->attach(bouton_inventory7, 6, 7, 1, 2);
	table_inventory->attach(bouton_inventory8, 7, 8, 1, 2);
}

//Fenetre A Propos, pop-up quand on clique sur l'icone correspondante
void FenetreJeu::afficherApropos() {
	Gtk::AboutDialog dialogue;
	dialogue.set_program_name("There is no Planet B");
	dialogue.set_version("1.0");
	dialogue.set_copyright("2022");
	dialogue.set_comments("Petit Escape Game codé pour le cours de C++");
	std::vector<Glib::ustring> listeAuteurs;
	listeAuteurs.push_back(": Mario et Romano");
	listeAuteurs.push_back("  EISE4 et MAIN4");
	dialogue.set_authors(listeAuteurs);
	dialogue.set_logo(Gdk::Pixbuf::create_from_file("Images/logo.jpg"));
	dialogue.set_position(Gtk::WIN_POS_CENTER);
	dialogue.run();
}

//Fenetre Regles, pop-up quand on clique sur l'icone correspondante
void FenetreJeu::afficherRegles() {
	FenetreImage regles("Images/regles.png");
	Gtk::Main::run(regles);
}


void FenetreJeu::popupMessage(const std::string message, const std::string title) {
	Gtk::MessageDialog dialogue(*this, message, false, Gtk::MESSAGE_WARNING);//, Gtk::BUTTONS_NONE);
	dialogue.set_title(title);
	dialogue.run();
}

void FenetreJeu::remplacerCartetoWhite(BoutonCarte & bouton) {
	int col = bouton.get_column(), line = bouton.get_line();
	table_images->remove(bouton);
	bouton.set_column(-1);
	bouton.set_line(-1);
	switch (col) {
		case 0: switch (line) {
					case 0: table_images->attach(bouton_0101, 0, 1, 0, 1); break;
					case 1: table_images->attach(bouton_0112, 0, 1, 1, 2); break;
				}
				break;
		case 1: switch (line) {
					case 0: table_images->attach(bouton_1201, 1, 2, 0, 1); break;
					case 1: table_images->attach(bouton_1212, 1, 2, 1, 2); break;
				}
				break;
		case 2: switch (line) {
					case 0: table_images->attach(bouton_2301, 2, 3, 0, 1); break;
					case 1: table_images->attach(bouton_2312, 2, 3, 1, 2); break;
				}
				break;
		case 3: switch (line) {
					case 0: table_images->attach(bouton_3401, 3, 4, 0, 1); break;
					case 1: table_images->attach(bouton_3412, 3, 4, 1, 2); break;
				}
				break;
	}
	show_all();
}

void FenetreJeu::remplacerWhitetoCarte(BoutonCarte & bouton) {
	std::tuple<int, int> res = getFirstWhiteCarte();
	int col = std::get<0>(res), line = std::get<1>(res);

	switch (col) {
		case 0: switch (line) {
					case 0: table_images->remove(bouton_0101); break;
					case 1: table_images->remove(bouton_0112); break;
				}
				break;
		case 1: switch (line) {
					case 0: table_images->remove(bouton_1201); break;
					case 1: table_images->remove(bouton_1212); break;
				}
				break;
		case 2: switch (line) {
					case 0: table_images->remove(bouton_2301); break;
					case 1: table_images->remove(bouton_2312); break;
				}
				break;
		case 3: switch (line) {
					case 0: table_images->remove(bouton_3401); break;
					case 1: table_images->remove(bouton_3412); break;
				}
				break;
	}
	table_images->attach(bouton, col, col+1, line, line+1);
	bouton.set_column(col);
	bouton.set_line(line);
	show_all();
}

void FenetreJeu::remplacerWhitetoObjet(BoutonCarte & bouton) {
	std::tuple<int, int> res = getFirstWhiteInventory();
	int col = std::get<0>(res), line = std::get<1>(res);

	switch (col) {
		case 0: table_inventory->remove(bouton_inventory1); break;
		case 1: table_inventory->remove(bouton_inventory2); break;
		case 2: table_inventory->remove(bouton_inventory3); break;
		case 3: table_inventory->remove(bouton_inventory4); break;
		case 4: table_inventory->remove(bouton_inventory5); break;
		case 5: table_inventory->remove(bouton_inventory6); break;
		case 6: table_inventory->remove(bouton_inventory7); break;
		case 7: table_inventory->remove(bouton_inventory8); break;
	}
	
	table_inventory->attach(bouton, col, col+1, 1, 2);
	bouton.set_column(col);
	bouton.set_line(line);
	show_all();
}

//En reaction a un appui sur le BoutonTexte bouton_carte
void FenetreJeu::requestCarte() {
	if (is_number(entry_carte_num.get_text())) {
		
		int num = std::stoi(entry_carte_num.get_text());
		
		if (num != 17 && num != 503 && num && 504) {
			Game->demande_affichage_carte(num);
			entry_carte_num.set_text("");
		}

		else {

			if (Game->affichage_carte_autorise(num)) { //pressing, revelation ou non-revelation
				Game->demande_affichage_carte(num);
				entry_carte_num.set_text("");
				if (num == 17) {bouton_pressing.zoom_Image();}
				else if (num == 503) {bouton_revelation.zoom_Image();}
				else {bouton_non_revelation.zoom_Image();}
				popupMessage("\nBravo ! Comme vous l'avez compris, vous avez trouvé une des fins possibles du jeu. \n\nLe jeu va donc quitter à la fermeture de cette fenêtre. \n\nSi vous souhaitez découvrir les autres fins possibles, n'hésitez pas à relancer une partie !", "Yeahhh");
				Gtk::Main::quit();
			}
 
			else {
				popupMessage("Vous n'avez pas encore le droit d'afficher cette carte", "Erreur");
			}

		}
		
		return;
	}
	else {popupMessage("Vous n'avez pas saisi un nombre entier", "Erreur");}
	entry_carte_num.set_text("");
}

//En reaction a un appui sur le BoutonTexte bouton_enigme
void FenetreJeu::requestRepondreEnigme() {
	
	if (is_number(entry_id_enigme.get_text())) {
		if (is_number(entry_reponse_enigme_l.get_text())) {
			Game->solution_enigme_valide(std::stoi(entry_id_enigme.get_text()), std::stoi(entry_reponse_enigme_l.get_text()));
			entry_id_enigme.set_text("");
			entry_reponse_enigme_l.set_text("");
			return;
		}
		else {popupMessage("Vous n'avez pas saisi un nombre entier pour la réponse", "Erreur");}
	}
	else {popupMessage("Vous n'avez pas saisi un nombre entier pour l'énigme", "Erreur");}
	entry_id_enigme.set_text("");
	entry_reponse_enigme_l.set_text("");
}

//En reaction a un appui sur le BoutonTexte bouton_combinaison
void FenetreJeu::requestCombinaison() {
	
	if (is_number(entry_objet_1.get_text())) {
		if (is_number(entry_objet_2.get_text())) {
			Game->combinaison_valide(std::stoi(entry_objet_1.get_text()), std::stoi(entry_objet_2.get_text()));
			entry_objet_1.set_text("");
			entry_objet_2.set_text("");
			return;
		}
		else {popupMessage("Vous n'avez pas saisi un nombre entier pour l'objet 2", "Erreur");}
	}
	else {popupMessage("Vous n'avez pas saisi un nombre entier pour l'objet 1", "Erreur");}
	entry_objet_1.set_text("");
	entry_objet_2.set_text("");
}

BoutonCarte* FenetreJeu::boutonCarteFromName(const std::string name) {
	
	std::size_t i;
	for (i = 0; i != allBoutonCartes.size(); i++) {
		//if (allBoutonCartes[i]->get_name() == name) {
		if (*allBoutonCartes[i] == name) {break;}
	}
	return allBoutonCartes[i];
}


BoutonCarte* FenetreJeu::boutonObjetFromName(const std::string name) {
		
	std::size_t i;
	for (i = 0; i != allBoutonObjets.size(); i++) {
		//if (allBoutonObjets[i]->get_name() == name) {
		if (*allBoutonObjets[i] == name) {break;}
	}
	return allBoutonObjets[i];
}

//Renvoyer les coordonnees de la 1ere case blanche disponible
std::pair<int, int> FenetreJeu::getFirstWhiteCarte() const {

	std::vector<Gtk::Widget*> children = table_images->get_children();
	int column = 4, line = 4;

	for (auto* it : children) {
		if (auto test = dynamic_cast<BoutonCarte*>(it)) {

			//if (test->get_name() == "white") {
			if (*test == "white") {
				
				if (test->get_column() < column || test->get_line() < line) {
					line = test->get_line();
					column = test->get_column();
				}
			}
		}
	}
	
	//En cas d'echec, mais normalement impossible : il y a au maximum 7 cartes affichees en meme temps sur le plateau, pour 8 cases au total
	if (line == 4 && column == 4) {
		line = -1;
		column = -1;
	}

	return std::make_pair(column, line);
}

//Renvoyer les coordonnees de la 1ere case blanche de l'inventaire disponible
std::pair<int, int> FenetreJeu::getFirstWhiteInventory() const {

	std::vector<Gtk::Widget*> children = table_inventory->get_children();
	int column = 8, line = 2;

	for (auto* it : children) {
		if (auto test = dynamic_cast<BoutonCarte*>(it)) {

			//if (test->get_name() == "white_inventory") {
			if (*test == "white_inventory") {
				
				if (test->get_column() < column || test->get_line() < line) {
					line = test->get_line();
					column = test->get_column();
				}
			}
		}
	}

	if (line == 8 && column == 2) {
		line = -1;
		column = -1;
	}

	return std::make_pair(column, line);
}


FenetreJeu::~FenetreJeu() {
	delete bouton_about;
	delete bouton_combinaisons;
	delete bouton_enigme;
	delete bouton_carte;
	delete table_zones_texte;
	delete table_images;
	delete table_big;
	delete Game;
}
