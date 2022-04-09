#include "Repository.h"

template <class TElem> void Repository<TElem>::add(const TElem& m) {
	Iterator<TElem> it = this->medicine.iterator();
	while (it.valid())
	{
		if (it.element() == m)
			throw RepositoryException("Medicine already exists!\n");
		it.next();
	}
	medicine.add(m);
}

template <class TElem> void Repository<TElem>::modify(const TElem& m) {
	Iterator<TElem> it = this->medicine.iterator();
	while (it.valid())
	{
		if (it.element() == m)
		{
			medicine.modify(m);
			return;
		}
		it.next();
	}
	throw RepositoryException("Medicine doesn't exist!\n");
}

template <class TElem> void Repository<TElem>::remove(const TElem& m) {
	Iterator<TElem> it = this->medicine.iterator();
	while (it.valid())
	{
		if (it.element() == m)
		{
			medicine.remove(m);
			return;
		}
		it.next();
	}
	throw RepositoryException("Medicine doesn't exist!\n");
}

template <class TElem> const TElem Repository<TElem>::find(const TElem& m) {
	Iterator<TElem> it = this->medicine.iterator();
	while (it.valid())
	{
		if (it.element() == m)
			return it.element();
		it.next();
	}
	throw RepositoryException("Medicine doesn't exist!\n");
}

template <class TElem> const Lista<TElem>& Repository<TElem>::get_all()const noexcept {
	return this->medicine;
}

template <class TElem> size_t Repository<TElem>::size_rep() const noexcept {
	return this->medicine.size();
}