#pragma once
//*******************************
//Name:WWBuffer.h
//Desc:Buffer
//Auth:Wawa
//Date:?
//Last:20161117
//*******************************

#include "WWNetMacros.h"

class WWBuffer:public Ref
{
public:
	friend class WWBufferPool;
public:
	//????????
	WWBuffer();
	explicit WWBuffer(int n_capacity);
	WWBuffer(const char* p_data, int u_len);
	virtual ~WWBuffer();
	static WWBuffer* create();
	static WWBuffer* create(int n_capacity);
	static WWBuffer* create(const char* p_data, int u_len);
	WWBuffer* copy();

public:
	//???????
	int length() const;
	int capacity() const;
	bool empty() const;
	char* data() const;
	void clear();

public:
	//??????? ????????
	unsigned int getWriterIndex() const;
	unsigned int getContentSize() const;
	unsigned int getReadableSize() const;
	unsigned int getReaderIndex() const;
	unsigned int getBufferSize() const;
	void discardReadContent();
	void skipData(int u_len);
	void moveWriterIndexToFront();
	void moveWriterIndexToBack();
	void moveReaderIndexToFront();
	void moveReaderIndexToBack();
	void markReaderIndex();
	void resetReaderIndex();
	void reset();
	void setReaderIndex(int u_pos);
	void setWriterIndex(int u_pos);
	void moveLeft(int u_len);
	void moveRight(int u_len);
	bool isReadable() const;
	bool isReadable(int u_len) const;

public:
	//?????????????
	void writeData(const char* p_data, int u_len);
	void writeLengthAndData(const char* p_data, int u_len);
	void writeChar(char data);
	void writeUChar(unsigned char data);
	void writeBoolean(bool isbool);
	void writeShort(short data);
	void writeUShort(unsigned short data);
	void writeInt(int data);
	void writeUInt(unsigned int data);
	void writeLongLong(long long data);
	void writeULongLong(unsigned long long data);
	void writeFloat(float data);
	void writeDouble(double data);
	void writeString(const char* p_data);
	void writeLengthAndString(const char* p_data);

public:
	//??????????? delete[]
	char* readWholeData();

public:
	//??????????????
	WWBuffer* readData(int u_len);
	WWBuffer* readLengthAndData();
	void readData(char* p_out_data, int u_len);
	char readChar();
	unsigned char readUChar();
	bool readBoolean();
	short readShort();
	unsigned short readUShort();
	int readInt();
	int readChar3ToInt();
	unsigned int readUInt();
	long long readLongLong();
	unsigned long long readULongLong();
	float readFloat();
	double readDouble();
	std::string readString(int u_len);
	std::string readLengthAndString();

public:
	void toRelease(); //?????????
protected:
	inline void _reallocBufferSizeInChanged(int u_len);
	inline void _reallocBufferSize();

protected:
	char* _p_buffer;
	int _u_write_pos;
	int _u_read_pos;
	int _u_mark_pos;
	int _u_content_size;
	int _u_buffer_size;

private:
	bool fromPool;
};

