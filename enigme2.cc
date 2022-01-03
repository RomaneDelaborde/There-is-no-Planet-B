#include "enigme2.hh"

Enigme2::Enigme2(std::string nom_carte, int id, std::vector<int> id_cartes_kick, int nb_essais, int code_solution, int id_carte_debloquee, std::string phrase):Enigme(nom_carte, id, id_cartes_kick, nb_essais, code_solution, id_carte_debloquee), _phrase(phrase)
{
  std::string alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  for(std::string::size_type i=0; i<alphabet.length(); i++) // création de _alphabet_indices
  {
      _alphabet_indices[alphabet[i]]=i+1; // +1 car on vaut A=1 et pas A=0
  }
}


void Enigme2::codage_jules_cesar(int decalage, bool sens_decalage)
{
  _phrase_codee=""; // initialisation de _phrase_codee

    for(std::string::size_type i=0; i<_phrase.length(); i++) // pour chaque caractère de la phrase
    {
        if(_phrase[i]==' ') // s'il s'agit d'un espace, on le recopie simplement
        {
          _phrase_codee+=' ';
        }

        else  // sinon c'est une lettre
        {
          int indice=_alphabet_indices[_phrase[i]]; // on retient l'indice de la lettre courante

          if(sens_decalage) // décalage vers la droite dans l'alphabet si sens_decalage=1
          {
            indice+=decalage; // indice devient l'indice décalé

          }
          else            // sinon décalage vers la gauche dans l'alphabet (si sens_decalage=0)
          {
            indice-=decalage; // indice devient l'indice décalé
          }
          indice=indice%_alphabet_indices.size(); // utilisation du modulo % si jamais on arrive à la fin de l'alphabet

          // Il ne reste plus qu'à chercher la valeur de la lettre correspondant à l'indice décalé dans le map _alphabet_indices

          std::map<char,int>::iterator iter = _alphabet_indices.begin(); // création itérateur pour parcourir le map

          while(iter != _alphabet_indices.end()) // parcours du map
          {
            char c =  iter->first; // c pour clé (=lettre)
            int v = iter->second; // v pour valeur (=indice)

            if(v==indice) // quand on a trouvé l'indice décalé, on ajoute sa lettre correspondante dans la _phrase_codee
            {
              _phrase_codee+=c;
              break;            // sortie en amont
            }
            ++iter;
          }
        }
    }
}
