echo "---- UPLOAD SOURCE ----";
git pull
git add --all;
git commit -m "up site";
git push;
cd ../baptiste-genest.github.io

echo "---- UPLOAD SITE ----"

git add --all
git commit -m "up site"
git push --force

cd -
