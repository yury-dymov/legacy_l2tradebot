#include "reader.h"

CatX::Reader3::Reader3 (const char * filename)
{
	fileName_ = filename;	
	fileSize_ = getFileSize_ ();
	currentPos_ = 0;
}

FILE * CatX::Reader3::fopen_ () const
{
	FILE *f = fopen (fileName_.c_str (), "rb");
	if (f != NULL)
	{
		return f;
	}
	else
	{
		std::cerr << fileName_ << " couldn't be opened!";
		exit (1);
	}
}

unsigned int CatX::Reader3::getFileSize_ () const
{
	FILE *f = fopen_ ();
	fseek (f, 0, SEEK_END);
	unsigned int ret = ftell (f);
	fclose (f);
	return ret;
}

void CatX::Reader3::init ()
{
	FILE * f = fopen_ ();
	char * arr = (char *) calloc (fileSize_, sizeof (char));
	next_.push_back (0);
	if (fread (arr, sizeof (char), fileSize_, f) == fileSize_)
	{
		if (fileSize_ >= 2 && arr[0] == -1 && arr[1] == -2)
		{
			for (unsigned int i = 2; i < fileSize_; i += 2)
			{
				if (arr[i] == '\n')
				{
					next_.push_back (i / 2 - 1);
				}
				data_ += arr[i];
			}	
		}
		else
		{
			for (unsigned int i = 0; i < fileSize_; ++i)
			{
				if (arr[i] == '\n')
				{
					next_.push_back (i);
				}
				data_ += arr[i];
			}	
		}
		free (arr);
		next_.push_back (data_.length ());
		fclose (f);
	}
	else
	{
		std::cerr << "Read Error!" << std::endl;
		fclose (f);
		exit (1);
	}
}

std::string CatX::Reader3::readNext ()
{
	if (next_ [currentPos_] != fileSize_)
	{
		++currentPos_;
		if (next_[currentPos_] - next_[currentPos_ - 1] > 2)
		{
			if (next_[currentPos_ - 1])
			{
				return data_.substr (next_[currentPos_ - 1] + 1, next_[currentPos_] - next_[currentPos_ - 1] - 1);
			}
			else
			{
				return data_.substr (0, next_[currentPos_] - next_[currentPos_ - 1]);
			}
		}
		else
		{
			return data_.substr (next_[currentPos_ - 1] + 1, 1);
		}
	}
	else
	{
		return "";
	}	
}

double CatX::Reader3::done () const
{
	return 1.0 * currentPos_ / next_.size ();
}


