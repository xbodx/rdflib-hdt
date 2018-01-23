/**
 * tripleid_iterator.hpp
 * Author: Thomas MINIER - MIT License 2017-2018
 */

#ifndef TRIPLEID_ITERATOR_HPP
#define TRIPLEID_ITERATOR_HPP

#include <string>
#include "Iterator.hpp"
#include "pyhdt_types.hpp"

/*!
 * TripleIDIterator iterates over IDs of RDF triples of an HDT document which match a triple pattern + limit + offset
 * \author Thomas Minier
 */
class TripleIDIterator {
private:
  hdt::IteratorTripleID *iterator;
  std::string subject;
  std::string predicate;
  std::string object;
  unsigned int limit;
  unsigned int offset;
  unsigned int resultsRead = 0;
public:
  /*!
   * Constructor
   * @param iterator [description]
   */
  TripleIDIterator(hdt::IteratorTripleID *_it, std::string _subj, std::string _pred, std::string _obj, unsigned int _limit, unsigned int _offset);

  /*!
   * Destructor
   */
  ~TripleIDIterator();

  /*!
   * Implementation for Python function "__repr__"
   * @return [description]
   */
  std::string python_repr();

  /*!
   * Implementation for Python function "__iter__"
   * @return [description]
   */
  TripleIDIterator* python_iter();

  /*!
   * Get the subject of the triple pattern currently evaluated.
   * An empty string represents a variable
   * @return [description]
   */
  std::string getSubject();

  /*!
   * Get the predicate of the triple pattern currently evaluated.
   * An empty string represents a variable
   * @return [description]
   */
  std::string getPredicate();

  /*!
   * Get the object of the triple pattern currently evaluated.
   * An empty string represents a variable
   * @return [description]
   */
  std::string getObject();

  /*!
   * Get the limit of the current iterator
   * @return [description]
   */
  unsigned int getLimit();

  /*!
   * Get the offset of the current iterator
   * @return [description]
   */
  unsigned int getOffset();

  /*!
   * Get the estimated cardinality of the pattern currently evaluated.
   * Offset & limit are not taken into account.
   * @return [description]
   */
  size_t estimateCardinality();

  /*!
   * Return true if the estimated number of results is accurate, false otherwise
   * @return [description]
   */
  bool accurateEstimation();

  /*!
   * Return true if the iterator still has items available, False otherwise.
   * @return [description]
   */
  bool hasNext();

  /**
   * Get the next item in the iterator, or raise py::StopIteration if the iterator has ended
   * @return [description]
   */
  triple_id next();
};

#endif /* TRIPLEID_ITERATOR_HPP */