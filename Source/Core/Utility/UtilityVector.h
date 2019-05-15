/*
 * UtilityVector.h
 *
 *  Created on: May 15, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_UTILITY_UTILITYVECTOR_H_
#define SOURCE_CORE_UTILITY_UTILITYVECTOR_H_

#include <vector>

namespace Utility
{
template<typename T>
class Container
{
public:
	Container(void);
	virtual ~Container(void);

public:
	inline size_t GetSubCount(void) const { return mSubElements.size(); }
	inline const T& GetSub(size_t index) const { return mSubElements.at(index); }

protected:
	std::vector<T> mSubElements;
};

} /* namespace Utility */

#endif /* SOURCE_CORE_UTILITY_UTILITYVECTOR_H_ */
