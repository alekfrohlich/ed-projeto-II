/*!
 * @file trie.h
 * @author Alek Frohlich, Nicolas Goeldner
 * @brief Arquivo de declarações e interface da Trie.
 * @version 1.0
 * @date 2019-06-20
 *
 * @copyright Copyright (c) 2019
 */

#ifndef STRUCTURES_TRIE
#define STRUCTURES_TRIE

#include <stdexcept>
#include <string>

//! Estruturas de Dados.
namespace structures {

//! Trie.
class Trie {
public: 
    //! Construtor.
    Trie();
    //! Destrutor.
    ~Trie();
    //! Insere chave na Trie.
    void insert(const std::string& key, unsigned long pos, unsigned long length);
    //! Busca chave na Trie.
    std::pair<int,int> search(const std::string& key);
private:
	//! Elemento-Nodo da Trie.
	Trie *children[26];
	//! Posicao
	unsigned long pos;
	//! Comprimento
	unsigned long length;
}

};

// implementacao incluida aqui
#include "trie.inc"

}  // namespace structures

#endif
