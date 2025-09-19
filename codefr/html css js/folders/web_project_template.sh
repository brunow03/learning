#!/bin/bash

# Script to generate standard web project folder structure
# Usage: ./create-web-project.sh

echo "Creating standard web project structure..."

# Create root directory
# mkdir -p project-root

# Create subdirectories
mkdir -p css/utilities
mkdir -p js/modules
mkdir -p js/utils
mkdir -p images/icons
mkdir -p images/backgrounds
mkdir -p images/content
mkdir -p fonts
mkdir -p vendor/bootstrap

# Create files
touch css/style.css
touch css/reset.css
touch css/layout.css
touch css/components.css
touch js/main.js
touch js/components.js
touch index.html
touch README.md

# Create basic content for main files
cat > index.html << EOF
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Project Title</title>
    <link rel="stylesheet" href="css/reset.css">
    <link rel="stylesheet" href="css/style.css">
</head>
<body>
    <h1>Welcome to Your Project</h1>
    <script src="js/main.js"></script>
</body>
</html>
EOF

cat > ./README.md << EOF
# Project Title

## Description
Brief description of your web project.

## Project Structure
\`\`\`
$(cd . && find . -type d -not -path '*/\.*' | sort | sed 's/\.//' | sed '/^$/d')
\`\`\`

## Installation
No installation required. Open index.html in a web browser.

## Usage
Describe how to use your project here.
EOF

cat > ./css/reset.css << EOF
/* Reset CSS */
* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
}
EOF

cat > ./css/style.css << EOF
/* Main Stylesheet */
body {
    font-family: Arial, sans-serif;
    line-height: 1.6;
    color: #333;
}
EOF

cat > ./js/main.js << EOF
// Main JavaScript File
document.addEventListener('DOMContentLoaded', function() {
    console.log('DOM loaded');
});
EOF

echo "Project structure created successfully!"
echo "Location: $(pwd)/."
echo ""
echo "Project tree:"
cd . && find . -not -path '*/\.*' | sort
