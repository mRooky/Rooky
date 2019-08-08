/*
 * KernelFile.h
 *
 *  Created on: May 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELFILE_H_
#define SOURCE_CORE_KERNEL_KERNELFILE_H_

namespace Kernel
{

template<typename T>
class File
{
	typedef T StringType;
public:
	File(void) = default;
	~File(void) = default;

public:
	inline const StringType& GetString(void) const
	{
		return m_file;
	}

private:
	StringType m_file;
};

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELFILE_H_ */
