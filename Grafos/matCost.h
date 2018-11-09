#ifndef MATCOST_HPP
#define MATCOST_HPP
#include <vector>
#include <limits>
template <typename T>
class GrafoP{
public:
	typedef T tCoste;
	typedef size_t vertice;//un valor entre 0 y grafop::numvert()-1
	static const tCoste INFINITO;

	explicit GrafoP(size_t n): costes(n,vector<tCoste>(n,INFINITO)){}
	size_t numvert()const{return costes.size();}
	const vector<tCoste>& operator[](vertice v) const {return costes[v];}
	vector<tCoste>& operator [](vertice v){return costes[v];}
	bool esDirigido() const;
private:
	vector<vector<tCoste>> costes;	

};


template<typename T>
const tCoste GrafoP<T>::INFINITO = std::numeric_limits<T>::max();