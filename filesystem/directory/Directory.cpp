//
// Created by alber on 20/07/2019.
//

#include "Directory.h"

/*crea, se ancora non esiste, l’oggetto di tipo
Directory e ne restituisce lo smart pointer.*/
std::shared_ptr<Directory> Directory::getRoot() {

}

/*crea un nuovo oggetto di tipo Directory, il cui nome è desunto dal parametro, e lo aggiunge alla cartella corrente. Se
risulta già presente, nella cartella corrente, un oggetto con il nome indicato, solleva
un’eccezione.*/
std::shared_ptr<Directory> Directory::addDirectory(std::string nome) {

}

/*aggiunge alla Directory un nuovo oggetto di tipo File, ricevendone come parametri il nome e la dimensione in byte;
l’aggiunta di un File con nome già presente nella cartella corrente non è permessa e causa
un’eccezione*/
std::shared_ptr<File> Directory::addFile(std::string nome, uintmax_t size) {

}

/*restituisce uno smart pointer all’oggetto
(Directory o File) di nome “name” contenuto nella directory corrente. Se inesistente,
restituisce uno shared_ptr vuoto. I nomi speciali “ .. ” e “ . ” permettono di ottenere
rispettivamente lo shared_pointer alla directory genitore di quella corrente, e quello
all’istanza stessa.*/
std::shared_ptr<Base> Directory::get(std::string name) {

}

std::shared_ptr<Directory> Directory::getDir(std::string name) {
    return std::shared_ptr<Directory>();
}

std::shared_ptr<File> Directory::getFile(std::string name) {
    return std::shared_ptr<File>();
}

void Directory::remove(std::string nome) {

}

void Directory::Is(int indent) const {

}
