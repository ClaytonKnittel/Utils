for file in "$@";
do
	clang-format --dry-run --Werror --ferror-limit=20 $file;
done
