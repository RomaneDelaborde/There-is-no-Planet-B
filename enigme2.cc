#include "enigme2.hh"

Enigme2::Enigme2(std::string nom_carte, int id, std::vector<int> id_cartes_kick, int nb_essais, int code_solution, int id_carte_debloquee, std::string phrase):Enigme(nom_carte, id, id_cartes_kick, nb_essais, code_solution, id_carte_debloquee), _phrase(phrase)
{
  std::string alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  for(std::string::size_type i=0; i<alphabet.length(); i++)
  {
      _alphabet_indices[alphabet[i]]=i+1; // this-> nécessaire ou pas ??
  }
}




void Enigme2::codage_jules_cesar(int decalage, bool sens_decalage)
{
  _phrase_codee="";

    for(std::string::size_type i=0; i<_phrase.length(); i++)
    {
        if(_phrase[i]==' ')
        {
          _phrase_codee+=' ';
        }

        else
        {
          int indice=_alphabet_indices[_phrase[i]];

          if(sens_decalage) // vers la droite si sens_decalage=1
          {
            indice+=decalage;

          }
          else
          {
            indice-=decalage;
          }
          indice=indice%_alphabet_indices.size();


          std::map<char,int>::iterator iter = _alphabet_indices.begin();
          while(iter != _alphabet_indices.end())
          {
            char c =  iter->first; // c pour clé
            int v = iter->second; // v pour valeur
            if(v==indice)
            {
              _phrase_codee+=c;
              break;
            }
            ++iter;
          }


        }
    }
}
