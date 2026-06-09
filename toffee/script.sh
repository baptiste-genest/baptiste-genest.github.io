mkdir -p resized

for img in *.jpg; do
    convert "$img" \
        -resize '1024x1024>' \
        "resized/$img"
done
