#include "SpriteSheet.hpp"

SpriteSheet::SpriteSheet(const string& filePath,int col, int row) : _col(col),_row(row){
    // texture.setSmooth(true);
    // unsigned int maxTextureSize = texture.getMaximumSize();

    if (!texture.loadFromFile(filePath)) {
        cout << "Failed to load texture: " + filePath << endl;
    }
    // if (texture.getSize().x > maxTextureSize || texture.getSize().y > maxTextureSize) {
    //     std::cerr << "Warning: Texture size exceeds maximum supported size!" << std::endl;
    //     // Handle resizing or splitting here.
    //     texture = resizeTexture(texture, maxTextureSize, maxTextureSize);
    // }
    sprite.setTexture(texture);

    _width = sprite.getLocalBounds().width / _col;
    _height = sprite.getLocalBounds().height / _row;

     // Get OpenGL texture ID from SFML texture
    textureID = texture.getNativeHandle();


}



sf::Texture SpriteSheet::resizeTexture(const sf::Texture& originalTexture, unsigned int maxWidth, unsigned int maxHeight) {
    // Calculate scale factors
    float scaleX = static_cast<float>(maxWidth) / originalTexture.getSize().x;
    float scaleY = static_cast<float>(maxHeight) / originalTexture.getSize().y;
    float scaleFactor = std::min(scaleX, scaleY);

    // Calculate new dimensions
    unsigned int newWidth = static_cast<unsigned int>(originalTexture.getSize().x * scaleFactor);
    unsigned int newHeight = static_cast<unsigned int>(originalTexture.getSize().y * scaleFactor);

    // Use RenderTexture to resize
    sf::RenderTexture renderTexture;
    if (!renderTexture.create(newWidth, newHeight)) {
        throw std::runtime_error("Failed to create render texture for resizing!");
    }

    renderTexture.clear();
    sf::Sprite tempSprite(originalTexture);
    tempSprite.setScale(scaleFactor, scaleFactor);
    renderTexture.draw(tempSprite);
    renderTexture.display();

    return renderTexture.getTexture();
}

float SpriteSheet::width(){
    return _width;
}

float SpriteSheet::height(){
   return  _height;
}

float SpriteSheet::nrSpriteSheet(){
    return _col * _row;
}

FloatRect SpriteSheet::boundingBox() const{
    return sprite.getLocalBounds();
}



Vector2f SpriteSheet::center(){
    return Vector2f(width() / 2, height() / 2);
}

Vector2f SpriteSheet::getOrigin(){
    return sprite.getOrigin();
}



void SpriteSheet::draw(RenderWindow& window,Vector2<float> position,Vector2<float> origin,float sheetIndex,bool mirror,Vector2<float> scale){
        //  float columnIndex = static_cast<int>(sheetIndex) % _col;
        //  float rowIndex = static_cast<int>(floor(sheetIndex / _col)) % _row;

        // if(mirror){
        // sprite.setPosition(-position.x - width(),position.y);
        // sprite.setScale(scale.x * -1,scale.y);
        // sprite.setTextureRect(IntRect(columnIndex * width(), rowIndex * height(),width(),height()));
        // window.draw(sprite);
        // }else{
        // sprite.setPosition(position.x,position.y);
        // sprite.setScale(scale.x,scale.y);
        // sprite.setTextureRect(IntRect(columnIndex * width(), rowIndex * height(),width(),height()));
        // window.draw(sprite);
        // }

        window.pushGLStates();
        // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // window.clear();
        glLoadIdentity();

        // Bind texture
        glBindTexture(GL_TEXTURE_2D, textureID);

        // Begin drawing quad
        glBegin(GL_QUADS);
        // -------- OPTION 1: Draw FULL sprite sheet --------
        // Uses entire texture
        glTexCoord2f(0.0f, 0.0f); glVertex2f(position.x,position.y); // Top-left
        glTexCoord2f(1.0f, 0.0f); glVertex2f(position.x + texture.getSize().x * scale.x, position.y); // Top-right
        glTexCoord2f(1.0f, 1.0f); glVertex2f(position.x + texture.getSize().x *scale.x, position.y + texture.getSize().y); // Bottom-right
        glTexCoord2f(0.0f, 1.0f); glVertex2f(position.x, position.y + texture.getSize().y); // 

        glEnd();




        /*  window.pushGLStates();
    glLoadIdentity();
    glBindTexture(GL_TEXTURE_2D, textureID);

    int totalColumns = _col;
    int totalRows = _row;
    int currentColumn = static_cast<int>(sheetIndex) % totalColumns;
    int currentRow = static_cast<int>(sheetIndex) / totalColumns;

    float texLeft = static_cast<float>(currentColumn) / totalColumns;
    float texRight = static_cast<float>(currentColumn + 1) / totalColumns;
    float texTop = static_cast<float>(currentRow) / totalRows;
    float texBottom = static_cast<float>(currentRow + 1) / totalRows;

    float drawWidth = width() * scale.x;
    float drawHeight = height() * scale.y;

    glBegin(GL_QUADS);
    glTexCoord2f(texLeft, texTop);      glVertex2f(position.x, position.y);                    // Top-left
    glTexCoord2f(texRight, texTop);     glVertex2f(position.x + drawWidth, position.y);        // Top-right
    glTexCoord2f(texRight, texBottom);  glVertex2f(position.x + drawWidth, position.y + drawHeight); // Bottom-right
    glTexCoord2f(texLeft, texBottom);   glVertex2f(position.x, position.y + drawHeight);       // Bottom-left
    glEnd();

    window.popGLStates(); */


         /* -------- OPTION 2: Draw SINGLE frame from sprite sheet --------
        int totalColumns = 14;
        int column = 1; // select frame
        float texTop = 0.0f;
        float texBottom = 1.0f;
        float drawWidth = spriteSheet.getSize().x / totalColumns;
        float drawHeight = spriteSheet.getSize().y;

        glTexCoord2f(texLeft, texTop); glVertex2f(100, 100); // Top-left
        glTexCoord2f(texRight, texTop); glVertex2f(100 + drawWidth, 100); // Top-right
        glTexCoord2f(texRight, texBottom); glVertex2f(100 + drawWidth, 100 + drawHeight); // Bottom-right
        glTexCoord2f(texLeft, texBottom); glVertex2f(100, 100 + drawHeight); // Bottom-left
        */


        window.popGLStates();
}
   