if not exist %cd%\build\gen (
	mkdir %cd%\build\gen
)
forfiles /p %cd%\src /m *.proto /c "protoc --proto_path=%cd%\src --cpp_out=%cd%\build\gen @file"