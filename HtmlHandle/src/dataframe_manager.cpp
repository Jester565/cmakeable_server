#include "dataframe_manager.h"
#include "dataframe_parser.h"
#include <utility>
#include <iterator>
#include <array>
#include <boost/make_shared.hpp>

namespace websocket
{
	dataframe_manager::dataframe_manager()
	{
		df_parser = new dataframe_parser();
	}

 boost::shared_ptr<websocket::dataframe> dataframe_manager::parse_data(const std::vector <unsigned char>& data, unsigned int size)
	{
		std::vector <unsigned char>::const_iterator end;
		if (size == USE_VEC_SIZE) {
			end = data.end();
		}
		else {
			end = data.begin() + size;
		}
		boost::shared_ptr<websocket::dataframe> df = boost::make_shared<websocket::dataframe>();
		std::pair <tribool, std::vector <unsigned char>::const_iterator> pResult = df_parser->parse(*df, data.begin(), end);
		tribool result = pResult.first;
		if (result)
		{
			return df;
		}
		return nullptr;
	}

	boost::shared_ptr<websocket::dataframe> dataframe_manager::parse_data(unsigned char* data, unsigned int size)
	{
			std::vector <unsigned char>::const_iterator end;
			boost::shared_ptr<websocket::dataframe> df = boost::make_shared<websocket::dataframe>();
			std::pair <tribool, unsigned char*> pResult = df_parser->parseArray(*df, data, size);
			tribool result = pResult.first;
			if (result)
			{
					return df;
			}
			return nullptr;
	}

	dataframe_manager::~dataframe_manager()
	{
	  delete df_parser;
	  df_parser = nullptr;
	}
}
