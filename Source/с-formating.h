#pragma once
#include <string>

using BufferUnsupportedSizeException = std::runtime_error;

template<unsigned int TMaxSize = 256U, typename... TArgs>
inline std::string StringFormatStatic(const std::string& format, TArgs&&... args)
{
	char buffer[TMaxSize];
	const int snprintf_result = std::snprintf(buffer, TMaxSize, format.data(), std::forward<TArgs>(args)...);
	if ((unsigned int)snprintf_result >= TMaxSize)
	{
		throw BufferUnsupportedSizeException("Unsupported buffer size, use more");
	}
	return std::string(buffer);
}

template<typename... TArgs>
inline std::string StringFormatDynamic(const std::string& format, TArgs&&... args)
{
	const int dyn_size = std::snprintf(nullptr, 0, format.data(), std::forward<TArgs>(args)...) + 1;

	std::unique_ptr<char[]> buffer(new char[dyn_size]);
	std::snprintf(buffer.get(), dyn_size, format.data(), std::forward<TArgs>(args)...);

	return std::string(std::move(buffer.get()));
}