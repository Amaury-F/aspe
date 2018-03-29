//
// Created by fauveama on 18/01/18.
//

#include "Game.h"
#include "events/EventHandler.h"

Game::Game() {
    graphicRenderer = new GraphicRenderer();
    eventHandler = new EventHandler(graphicRenderer->getContext());
    gameModel = new GameModel();
}

Game::~Game() {
    delete eventHandler;
    delete graphicRenderer;
    delete gameModel;
}

void Game::handleEvents() {
    eventHandler->pullEvents();
}

void Game::updateModel() {
    gameModel->update(eventHandler->getPressedKeys());
}

void Game::renderWindow() {
    graphicRenderer->render(gameModel->getEntities());
}

bool Game::isRunning() {
    return graphicRenderer->getContext()->isOpen();
}
